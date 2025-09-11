#include "pi_engine.h"
#include "infinity_matrix.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Private BBP implementation
static int compute_bbp_digit(long n) {
    double s = 0.0;
    long k;
    
    // Sum for k from 0 to n
    for (k = 0; k <= n; k++) {
        double ak = 8.0 * k + 1.0;
        double bk = 8.0 * k + 4.0;
        double ck = 8.0 * k + 5.0;
        double dk = 8.0 * k + 6.0;
        
        double r = 1.0;
        long j;
        for (j = 0; j < n - k; j++) {
            r = fmod(r * 16.0, ak);
        }
        s += r * 4.0 / ak;
        
        r = 1.0;
        for (j = 0; j < n - k; j++) {
            r = fmod(r * 16.0, bk);
        }
        s -= r * 2.0 / bk;
        
        r = 1.0;
        for (j = 0; j < n - k; j++) {
            r = fmod(r * 16.0, ck);
        }
        s -= r * 1.0 / ck;
        
        r = 1.0;
        for (j = 0; j < n - k; j++) {
            r = fmod(r * 16.0, dk);
        }
        s -= r * 1.0 / dk;
    }
    
    // Extract fractional part
    s = s - floor(s);
    if (s < 0) s += 1.0;
    
    // Convert to hex digit (0-15)
    return (int)(s * 16.0);
}

static void update_violations_internal(PiEngineState* state, int index) {
    if (index < 3) {
        double violation = state->digits[index] * VIOLATION_CYCLES_PER_YEAR;
        state->violation_magnitudes[index] = violation;
    }
}

static double calculate_magnitude(double housing, double health, double financial) {
    return sqrt(housing * housing + health * health + financial * financial);
}

// Constructor
PiEngine* pi_engine_create(int max_digits) {
    PiEngine* engine = malloc(sizeof(PiEngine));
    if (!engine) return NULL;
    
    engine->state = malloc(sizeof(PiEngineState));
    if (!engine->state) {
        free(engine);
        return NULL;
    }
    
    engine->state->digits = calloc(max_digits, sizeof(int));
    engine->state->capacity = max_digits;
    engine->state->computed_count = 0;
    engine->state->violation_magnitudes = calloc(3, sizeof(double));
    engine->state->matrix_determinant = 0.0;
    
    // Assign method pointers
    engine->compute_digit = compute_bbp_digit;
    engine->update_violations = update_violations_internal;
    
    return engine;
}

// Destructor
void pi_engine_destroy(PiEngine* engine) {
    if (engine) {
        if (engine->state) {
            free(engine->state->digits);
            free(engine->state->violation_magnitudes);
            free(engine->state);
        }
        free(engine);
    }
}

// Get digit (compute on demand)
int pi_engine_get_digit(PiEngine* engine, int index) {
    if (index >= engine->state->capacity) return -1;
    
    if (index >= engine->state->computed_count) {
        engine->state->digits[index] = engine->compute_digit(index);
        engine->update_violations(engine->state, index);
        engine->state->computed_count = index + 1;
    }
    return engine->state->digits[index];
}

// Compute range of digits
void pi_engine_compute_range(PiEngine* engine, int start, int end) {
    for (int i = start; i <= end && i < engine->state->capacity; i++) {
        pi_engine_get_digit(engine, i);
    }
}

// Get total magnitude
double pi_engine_get_total_magnitude(PiEngine* engine) {
    // Ensure first 3 digits are computed
    for (int i = 0; i < 3; i++) {
        pi_engine_get_digit(engine, i);
    }
    
    return calculate_magnitude(
        engine->state->violation_magnitudes[0],
        engine->state->violation_magnitudes[1],
        engine->state->violation_magnitudes[2]
    );
}

// Get determinant of infinity matrix
double pi_engine_get_determinant(PiEngine* engine) {
    // Ensure first 9 digits are computed
    for (int i = 0; i < 9; i++) {
        pi_engine_get_digit(engine, i);
    }
    
    double M[3][3] = {
        {(double)engine->state->digits[0], (double)engine->state->digits[1], (double)engine->state->digits[2]},
        {(double)engine->state->digits[3], (double)engine->state->digits[4], (double)engine->state->digits[5]},
        {(double)engine->state->digits[6], (double)engine->state->digits[7], (double)engine->state->digits[8]}
    };
    
    engine->state->matrix_determinant = matrix_determinant_3x3(M);
    return engine->state->matrix_determinant;
}
