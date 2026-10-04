#include <stdio.h>
#include <limits.h>

int minCoins(int coins[], int n, int V) {
    int dp[V + 1];
    dp[0] = 0;

    for (int i = 1; i <= V; i++) {
        dp[i] = INT_MAX;
    }

    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                int sub_res = dp[i - coins[j]];
                if (sub_res != INT_MAX && sub_res + 1 < dp[i]) {
                    dp[i] = sub_res + 1;
                }
            }
        }
    }
    return (dp[V] == INT_MAX) ? -1 : dp[V];
}

int main() {
    int coins[] = {1, 2, 5};
    int n = sizeof(coins) / sizeof(coins[0]);
    int V = 11;

    printf("--- QUESTION 1: MINIMUM COIN CHANGE ---\n");
    printf("Target Amount: %d\n", V);
    printf("Minimum Coins Needed: %d\n", minCoins(coins, n, V));
    return 0;
}