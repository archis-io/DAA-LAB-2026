#include <stdio.h>
#include <math.h>

typedef struct {
    char name[30];
    double value;
} Function;

int main() {
    double n = 1000.0; // Large value of n

    Function funcs[] = {
        {"1 / n", 1.0 / n},
        {"2^32", pow(2, 32)},
        {"log2(n)", log2(n)},
        {"12 * sqrt(n)", 12.0 * sqrt(n)},
        {"50 * n^0.5", 50.0 * pow(n, 0.5)},
        {"n^0.51", pow(n, 0.51)},
        {"100 * n", 100.0 * n},
        {"n * log2(n)", n * log2(n)},
        {"32 * n * log2(n)", 32.0 * n * log2(n)},
        {"n^2 - 324", pow(n, 2) - 324},
        {"2 * n^3", 2.0 * pow(n, 3)},
        {"3^n", pow(3, 100)} // Evaluated at large n
    };

    int total = sizeof(funcs) / sizeof(funcs[0]);

    printf("--- Functions ordered by increasing growth rate (Theoretical & Computed at n=1000) ---\n\n");
    for (int i = 0; i < total; i++) {
        printf("%2d. %-20s (Val at n=1000: %e)\n", i + 1, funcs[i].name, funcs[i].value);
    }

    return 0;
}