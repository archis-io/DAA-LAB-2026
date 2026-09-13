#include <stdio.h>

void hit_moving_target(int n) {
    printf("Shooting Sequence: ");
    // Pass 1: Catches target if it started at an even position
    for (int i = 2; i <= n - 1; i++) printf("%d ", i);
    // Pass 2: Catches target if it started at an odd position
    for (int i = 2; i <= n - 1; i++) printf("%d ", i);
    printf("\nTotal Shots: %d\n", 2 * (n - 2));
}

int main() {
    int n = 5;
    printf("--- QUESTION 5: HITTING A MOVING TARGET ---\n");
    printf("Hiding Spots (n): %d\n", n);
    hit_moving_target(n);
    return 0;
}