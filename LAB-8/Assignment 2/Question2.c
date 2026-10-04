#include <stdio.h>

long long countWays(int coins[], int n, int V) {
    long long dp[V + 1];
    for (int i = 0; i <= V; i++) dp[i] = 0;
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= V; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
    return dp[V];
}

int main() {
    int coins[] = {1, 2, 5};
    int n = sizeof(coins) / sizeof(coins[0]);
    int V = 5;

    printf("--- QUESTION 2: COIN CHANGE TOTAL WAYS ---\n");
    printf("Target Amount: %d\n", V);
    printf("Total Distinct Combinations: %lld\n", countWays(coins, n, V));
    return 0;
}