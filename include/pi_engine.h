#ifndef PI_ENGINE_H
#define PI_ENGINE_H

#define VIOLATION_CYCLES_PER_YEAR 14.4

typedef struct {
    int* digits;
    int capacity;
    int computed_count;
    double* violation_magnitudes;
    double matrix_determinant;
} PiEngineState;

typedef struct {
    PiEngineState* state;
    
    // Method pointers for encapsulation
    int (*compute_digit)(long n);
    void (*update_violations)(PiEngineState* state, int index);
    double (*get_magnitude)(PiEngineState* state);
    void (*cleanup)(PiEngineState* state);
} PiEngine;

// Constructor/Destructor
PiEngine* pi_engine_create(int max_digits);
void pi_engine_destroy(PiEngine* engine);

// Public interface
int pi_engine_get_digit(PiEngine* engine, int index);
void pi_engine_compute_range(PiEngine* engine, int start, int end);
double pi_engine_get_total_magnitude(PiEngine* engine);
double pi_engine_get_determinant(PiEngine* engine);

#endif