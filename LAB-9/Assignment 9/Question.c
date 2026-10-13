#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int weight;
    int depth;
} Node;

// Hu-Tucker Phase 1: Combination phase simulation (merging compatible pairs while preserving order)
int huTuckerSimulation(int weights[], int n) {
    Node nodes[100];
    for (int i = 0; i < n; i++) {
        nodes[i].weight = weights[i];
        nodes[i].depth = 0;
    }

    int current_size = n;
    int total_cost = 0;

    while (current_size > 1) {
        int min_sum = INT_MAX;
        int merge_idx = -1;

        // Find adjacent compatible pair with minimum weight sum
        for (int i = 0; i < current_size - 1; i++) {
            int sum = nodes[i].weight + nodes[i + 1].weight;
            if (sum < min_sum) {
                min_sum = sum;
                merge_idx = i;
            }
        }

        total_cost += min_sum;
        nodes[merge_idx].weight = min_sum;

        // Shift remaining items
        for (int i = merge_idx + 1; i < current_size - 1; i++) {
            nodes[i] = nodes[i + 1];
        }
        current_size--;
    }
    return total_cost;
}

int main() {
    int weights[] = {10, 20, 15, 30, 25};
    int n = sizeof(weights) / sizeof(weights[0]);

    printf("--- QUESTION 9: HU-TUCKER GREEDY SIMULATION ---\n");
    int total_cost = huTuckerSimulation(weights, n);
    printf("Total Weighted Path Length Sum: %d\n", total_cost);
    return 0;
}