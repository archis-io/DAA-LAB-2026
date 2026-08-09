#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double simulate_coin(long tosses, double p_head) {
    long heads = 0;
    for (long i = 0; i < tosses; i++) {
        double r = (double)rand() / RAND_MAX;
        if (r < p_head) heads++;
    }
    return (double)heads / tosses;
}

int main() {
    srand(time(NULL));
    long trials[] = {100, 1000, 10000, 100000, 1000000};
    int n_trials = sizeof(trials) / sizeof(trials[0]);

    printf("Tosses\t\tFair Coin (p=0.5)\tBiased Coin (p=0.7)\n");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < n_trials; i++) {
        double fair = simulate_coin(trials[i], 0.5);
        double biased = simulate_coin(trials[i], 0.7);
        printf("%-12ld\t%-18.4f\t%-18.4f\n", trials[i], fair, biased);
    }

    return 0;
}