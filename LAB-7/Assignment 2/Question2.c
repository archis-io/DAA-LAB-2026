#include <stdio.h>
#include <limits.h>

// DP solution for E eggs and F floors: O(E * F^2) time, O(E * F) space
int egg_drop(int E, int F) {
    int dp[E + 1][F + 1];

    for (int i = 1; i <= E; i++) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    for (int j = 1; j <= F; j++) dp[1][j] = j;

    for (int i = 2; i <= E; i++) {
        for (int j = 2; j <= F; j++) {
            dp[i][j] = INT_MAX;
            for (int k = 1; k <= j; k++) {
                int res = 1 + (dp[i - 1][k - 1] > dp[i][j - k] ? dp[i - 1][k - 1] : dp[i][j - k]);
                if (res < dp[i][j]) dp[i][j] = res;
            }
        }
    }
    return dp[E][F];
}

int main() {
    int eggs = 2, floors = 100;
    printf("--- QUESTION 2: SUPER EGG TESTING EXPERIMENT ---\n");
    printf("Eggs: %d, Floors: %d\n", eggs, floors);
    printf("Minimum Guaranteed Drops: %d\n", egg_drop(eggs, floors));
    return 0;
}