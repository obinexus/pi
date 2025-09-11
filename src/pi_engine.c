#include "pi_engine.h"
#include <stdlib.h>
#include <math.h>

// Private methods
static int compute_bbp_digit(long n) {
    double s = 0.0;
    long k;
    
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
        
        // ... rest of BBP formula
    }
    
    s = s - floor(s);
    if (s < 0) s += 1.0;
    return (int)(s * 16.0);
}

static void update_violations_internal(PiEngineState* state, int index) {
    if (index < 3) {
        double violation = state->digits[index] * VIOLATION_CYCLES_PER_YEAR;
        state->violation_magnitudes[index] = violation;
    }
}

// Constructor
PiEngine* pi_engine_create(int max_digits) {
    PiEngine* engine = malloc(sizeof(PiEngine));
    engine->state = malloc(sizeof(PiEngineState));
    
    engine->state->digits = calloc(max_digits, sizeof(int));
    engine->state->capacity = max_digits;
    engine->state->computed_count = 0;
    engine->state->violation_magnitudes = calloc(3, sizeof(double));
    
    // Assign method pointers
    engine->compute_digit = compute_bbp_digit;
    engine->update_violations = update_violations_internal;
    
    return engine;
}

// Public getter - ensures state isolation
int pi_engine_get_digit(PiEngine* engine, int index) {
    if (index >= engine->state->computed_count) {
        // Compute on demand
        engine->state->digits[index] = engine->compute_digit(index);
        engine->update_violations(engine->state, index);
        engine->state->computed_count = index + 1;
    }
    return engine->state->digits[index];
}
