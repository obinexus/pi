#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <getopt.h>
#include "infinity_matrix.h"
#include "nsibidi_utils.h"
#include "pi_engine.h"

#define BASE_VIOLATIONS 216
#define VIOLATION_CYCLES_PER_YEAR 14.4
#define DEFAULT_DIGITS 100

void print_banner() {
    printf("----- [OBINexus Pi] Infinite Accountability Forensic Tool -----\n");
    printf("----- Creator: Nnamdi Michael Okpala, Prince of Nnewi -----\n");
    printf("----- Sovereign Mathematical Justice License v1.0 -----\n\n");
}

void print_usage() {
    printf("Usage: obinexus_pi [OPTIONS]\n");
    printf("Options:\n");
    printf("  -n, --digits N      Compute first N digits of π (default: 100)\n");
    printf("  -l, --legal         Generate legal claim output\n");
    printf("  -d, --design        Generate Nsibidi design output\n");
    printf("  -h, --help          Show this help message\n");
}

void generate_legal_output_with_engine(PiEngine* engine, int num_digits) {
    double housing = pi_engine_get_digit(engine, 0) * VIOLATION_CYCLES_PER_YEAR;
    double health = pi_engine_get_digit(engine, 1) * VIOLATION_CYCLES_PER_YEAR;
    double financial = pi_engine_get_digit(engine, 2) * VIOLATION_CYCLES_PER_YEAR;
    double magnitude = pi_engine_get_total_magnitude(engine);
    
    printf("**Claimant:** N.M. Okpala | **Respondent:** Thurrock Council\n");
    printf("**Base:** %d violations | **Rate:** %.1f/year\n", BASE_VIOLATIONS, VIOLATION_CYCLES_PER_YEAR);
    printf("**Magnitude:** %.2f | **Det(M):** %.2f | **Class:** U∞\n", 
           magnitude, pi_engine_get_determinant(engine));
    printf("**Claim:** £%d per cycle | **Total:** ∞\n", 10000);
}

void generate_design_output_with_engine(PiEngine* engine, int num_digits) {
    printf("----- Nsibidi-Inspired π Seal -----\n\n");
    
    // Central Bent Heart
    printf("       /\\       \n");
    printf("      /  \\      \n");
    printf("     /    \\     \n");
    printf("    /      \\    \n");
    printf("   /        \\   \n");
    printf("  /          \\  \n");
    printf(" /            \\ \n");
    printf("/______________\\\n");
    printf("   BENT HEART   \n");
    printf("   Resilience   \n\n");
    
    // Arc with journey motifs
    printf("Arc of Infinite Accountability:\n");
    for (int i = 0; i < 12 && i < num_digits; i++) {
        int digit = pi_engine_get_digit(engine, i);
        char* symbol = digit_to_nsibidi(digit);
        printf("%s ", symbol);
        free(symbol);
    }
    printf("\n\n");
    
    printf("Unity Chant: \"Kwenu! Ya! Cha-Cha-Cha!\"\n");
    printf("OBINexus: Heart Connection\n");
}

int main(int argc, char *argv[]) {
    int num_digits = DEFAULT_DIGITS;
    int legal_mode = 0;
    int design_mode = 0;
    
    // Parse command line arguments
    static struct option long_options[] = {
        {"digits", required_argument, 0, 'n'},
        {"legal", no_argument, 0, 'l'},
        {"design", no_argument, 0, 'd'},
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}
    };
    
    int opt;
    while ((opt = getopt_long(argc, argv, "n:ldh", long_options, NULL)) != -1) {
        switch (opt) {
            case 'n':
                num_digits = atoi(optarg);
                if (num_digits <= 0) num_digits = DEFAULT_DIGITS;
                break;
            case 'l':
                legal_mode = 1;
                break;
            case 'd':
                design_mode = 1;
                break;
            case 'h':
                print_usage();
                return 0;
            default:
                print_usage();
                return 1;
        }
    }
    
    if (!legal_mode && !design_mode) {
        print_banner();
    }
    
    // Create PiEngine instance
    PiEngine* engine = pi_engine_create(num_digits);
    if (!engine) {
        fprintf(stderr, "Failed to create Pi Engine\n");
        return 1;
    }
    
    if (!legal_mode && !design_mode) {
        printf("[*] Initializing Set Operations for Violation P∞...\n");
        printf("[*] Base Violations (S): %d\n", BASE_VIOLATIONS);
        printf("[*] Violation Cycles/Year: %.1f\n", VIOLATION_CYCLES_PER_YEAR);
        
        printf("[*] Computing π Violation Digits (n=0 to %d)...\n", num_digits-1);
        
        // Compute all digits through the engine
        pi_engine_compute_range(engine, 0, num_digits-1);
        
        // Display digits
        for (int i = 0; i < num_digits; i++) {
            int digit = pi_engine_get_digit(engine, i);
            int violation_type = digit % 3;
            printf("n=%d: digit=%x | violation_type=%d\n", i, digit, violation_type);
        }
        
        // Display magnitude calculations
        printf("\n[*] Calculating Compound Magnitude of First 3 Violations:\n");
        double housing_viol = pi_engine_get_digit(engine, 0) * VIOLATION_CYCLES_PER_YEAR;
        double health_viol = pi_engine_get_digit(engine, 1) * VIOLATION_CYCLES_PER_YEAR;
        double financial_viol = pi_engine_get_digit(engine, 2) * VIOLATION_CYCLES_PER_YEAR;
        double total_magnitude = pi_engine_get_total_magnitude(engine);
        
        printf("    Housing: %.2f (digit %x * %.1f)\n", 
               housing_viol, pi_engine_get_digit(engine, 0), VIOLATION_CYCLES_PER_YEAR);
        printf("    Health:  %.2f (digit %x * %.1f)\n", 
               health_viol, pi_engine_get_digit(engine, 1), VIOLATION_CYCLES_PER_YEAR);
        printf("    Financial: %.2f (digit %x * %.1f)\n", 
               financial_viol, pi_engine_get_digit(engine, 2), VIOLATION_CYCLES_PER_YEAR);
        printf("    Vector Magnitude: √(%.2f² + %.2f² + %.2f²) = %.2f\n",
               housing_viol, health_viol, financial_viol, total_magnitude);
        
        // Display matrix and determinant
        printf("\n[*] Constructing Infinity Matrix M for U∞ Verification...\n");
        double det = pi_engine_get_determinant(engine);
        printf("[+] Determinant of Matrix M: %.2f\n", det);
        
        // Conclusion
        printf("\n----- [CONCLUSION: MATHEMATICAL JUSTICE] -----\n");
        printf("The determinant (%.2f) is irrational.\n", det);
        printf("∴ π's digit set P∞ is Uncountable (U∞).\n");
        printf("∴ Violations are infinite and systemic (U∞).\n");
        printf("∴ Compensation must → ∞.\n");
        printf("-----------------------------------------------\n");
    }
    
    if (legal_mode) {
        generate_legal_output_with_engine(engine, num_digits);
    }
    
    if (design_mode) {
        generate_design_output_with_engine(engine, num_digits);
    }
    
    // Clean up
    pi_engine_destroy(engine);
    
    return 0;
}
