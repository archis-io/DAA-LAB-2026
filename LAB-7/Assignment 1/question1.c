#include <stdio.h>
#include <stdlib.h>

// Formula for minimum coin moves to invert an equilateral coin triangle of height n
int min_coin_moves(int n) {
    return (n * (n + 1)) / 6;
}

int main() {
    int n = 4; // Height of triangle (10 coins total)
    int moves = min_coin_moves(n);

    printf("--- QUESTION 1: INVERT THE COIN-TRIANGLE ---\n");
    printf("Triangle Height (n): %d\n", n);
    printf("Total Coins: %d\n", (n * (n + 1)) / 2);
    printf("Minimum Moves Required: %d\n", moves);

    return 0;
}