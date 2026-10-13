#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

int candy(int ratings[], int n) {
    int candies[n];
    for (int i = 0; i < n; i++) candies[i] = 1;

    // Left-to-Right pass
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Right-to-Left pass
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    int total_candies = 0;
    for (int i = 0; i < n; i++) {
        total_candies += candies[i];
    }
    return total_candies;
}

int main() {
    int ratings[] = {1, 0, 2};
    int n = sizeof(ratings) / sizeof(ratings[0]);

    printf("--- QUESTION 5: CANDY DISTRIBUTION PROBLEM ---\n");
    printf("Minimum Total Candies Required: %d\n", candy(ratings, n));
    return 0;
}