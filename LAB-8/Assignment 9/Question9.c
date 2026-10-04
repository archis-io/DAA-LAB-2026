#include <stdio.h>
#include <stdlib.h>

void analyzeSingle(unsigned long long n) {
    unsigned long long temp = n;
    int steps = 0;
    unsigned long long peak = n;

    while (temp != 1) {
        if (temp % 2 == 0) {
            temp /= 2;
        } else {
            temp = 3 * temp + 1;
        }
        if (temp > peak) peak = temp;
        steps++;
    }
    printf("Initial value: %llu | Total Stopping Time: %d | Peak Value: %llu\n", n, steps, peak);
}

void analyzeInterval(unsigned long long a, unsigned long long b) {
    int max_steps = 0;
    unsigned long long max_steps_num = a;
    unsigned long long highest_peak = 0;

    for (unsigned long long i = a; i <= b; i++) {
        unsigned long long temp = i;
        int steps = 0;
        unsigned long long peak = i;

        while (temp != 1) {
            if (temp % 2 == 0) temp /= 2;
            else temp = 3 * temp + 1;
            if (temp > peak) peak = temp;
            steps++;
        }

        if (steps > max_steps) {
            max_steps = steps;
            max_steps_num = i;
        }
        if (peak > highest_peak) {
            highest_peak = peak;
        }
    }

    printf("\n--- Interval [%llu, %llu] Analysis ---\n", a, b);
    printf("Number with Max Steps (%d): %llu\n", max_steps, max_steps_num);
    printf("Highest Peak Reached in Range: %llu\n", highest_peak);
}

int main() {
    printf("--- QUESTION 9: COLLATZ CONJECTURE TRAJECTORY ---\n");
    analyzeSingle(27);
    analyzeInterval(1, 100);
    return 0;
}