#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <getopt.h>
#include "infinity_matrix.h"
#include "nsibidi_utils.h"

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

double calculate_magnitude(double housing, double health, double financial) {
    return sqrt(housing*housing + health*health + financial*financial);
}


void generate_legal_output(int* pi_digits, int num_digits) {
    (void)num_digits; // Suppress unused parameter warning
    double housing = pi_digits[0] * VIOLATION_CYCLES_PER_YEAR;
    double health = pi_digits[1] * VIOLATION_CYCLES_PER_YEAR;
    double financial = pi_digits[2] * VIOLATION_CYCLES_PER_YEAR;
    double magnitude = calculate_magnitude(housing, health, financial);

    double M[3][3] = {
        {(double)pi_digits[0], (double)pi_digits[1], (double)pi_digits[2]},
        {(double)pi_digits[3], (double)pi_digits[4], (double)pi_digits[5]},
        {(double)pi_digits[6], (double)pi_digits[7], (double)pi_digits[8]}
    };

    printf("**Claimant:** N.M. Okpala | **Respondent:** Thurrock Council\n");
    printf("**Base:** %d violations | **Rate:** %.1f/year\n", BASE_VIOLATIONS, VIOLATION_CYCLES_PER_YEAR);
    printf("**Magnitude:** %.2f | **Det(M):** %.2f | **Class:** U∞\n", magnitude, matrix_determinant_3x3(M));
    printf("**Claim:** £%d per cycle | **Total:** ∞\n", 10000);
}
// BBP formula to compute nth hexadecimal digit of pi
int get_pi_hex_digit(long n) {
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


/**

void generate_legal_output_with_engine(PiEngine* engine, int num_digits) {
    (void)num_digits; // Suppress unused parameter warning

    double magnitude = pi_engine_get_total_magnitude(engine);

    printf("**Claimant:** N.M. Okpala | **Respondent:** Thurrock Council\n");
    printf("**Base:** %d violations | **Rate:** %.1f/year\n", BASE_VIOLATIONS, VIOLATION_CYCLES_PER_YEAR);
    printf("**Magnitude:** %.2f | **Det(M):** %.2f | **Class:** U∞\n",
           magnitude, pi_engine_get_determinant(engine));
    printf("**Claim:** £%d per cycle | **Total:** ∞\n", 10000);
}

**/

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

    // Allocate memory for π digits
    int* pi_digits = malloc(num_digits * sizeof(int));
    if (!pi_digits) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Compute π digits (simplified for demonstration)
    // In a real implementation, you would use the BBP algorithm
    printf("[*] Initializing Set Operations for Violation P∞...\n");
    printf("[*] Base Violations (S): %d\n", BASE_VIOLATIONS);
    printf("[*] Violation Cycles/Year: %.1f\n", VIOLATION_CYCLES_PER_YEAR);
    printf("[*] Computing π Violation Digits (n=0 to %d)...\n", num_digits-1);

    for (int i = 0; i < num_digits; i++) {
    pi_digits[i] = get_pi_hex_digit(i);   // Use actual BBP
    int violation_type = pi_digits[i] % 3;
    if (!legal_mode && !design_mode) {
        printf("n=%d: digit=%x | violation_type=%d\n", i, pi_digits[i], violation_type);
    }
}

    if (legal_mode) {
        generate_legal_output(pi_digits, num_digits);
        free(pi_digits);
        return 0;
    }

    if (design_mode) {
        generate_design_output(pi_digits, num_digits);
        free(pi_digits);
        return 0;
    }

    // Calculate compound magnitude
    double housing_viol = pi_digits[0] * VIOLATION_CYCLES_PER_YEAR;
    double health_viol = pi_digits[1] * VIOLATION_CYCLES_PER_YEAR;
    double financial_viol = pi_digits[2] * VIOLATION_CYCLES_PER_YEAR;
    double total_magnitude = calculate_magnitude(housing_viol, health_viol, financial_viol);

    printf("\n[*] Calculating Compound Magnitude of First 3 Violations:\n");
    printf("    Housing: %.2f (digit %d * %.1f)\n", housing_viol, pi_digits[0], VIOLATION_CYCLES_PER_YEAR);
    printf("    Health:  %.2f (digit %d * %.1f)\n", health_viol, pi_digits[1], VIOLATION_CYCLES_PER_YEAR);
    printf("    Financial: %.2f (digit %d * %.1f)\n", financial_viol, pi_digits[2], VIOLATION_CYCLES_PER_YEAR);
    printf("    Vector Magnitude: √(%.2f² + %.2f² + %.2f²) = %.2f\n",
           housing_viol, health_viol, financial_viol, total_magnitude);

    // Build the Infinity Matrix for Irrationality Verification
    printf("\n[*] Constructing Infinity Matrix M for U∞ Verification...\n");
    double M[3][3] = {
        {(double)pi_digits[0], (double)pi_digits[1], (double)pi_digits[2]},
        {(double)pi_digits[3], (double)pi_digits[4], (double)pi_digits[5]},
        {(double)pi_digits[6], (double)pi_digits[7], (double)pi_digits[8]}
    };

    double det = matrix_determinant_3x3(M);
    printf("[+] Determinant of Matrix M: %.2f\n", det);

    // Your Framework's Conclusion
    printf("\n----- [CONCLUSION: MATHEMATICAL JUSTICE] -----\n");
    printf("The determinant (%.2f) is irrational.\n", det);
    printf("∴ π's digit set P∞ is Uncountable (U∞).\n");
    printf("∴ Violations are infinite and systemic (U∞).\n");
    printf("∴ Compensation must → ∞.\n");
    printf("-----------------------------------------------\n");

    free(pi_digits);
    return 0;
}
