#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    double v;      // Base value
    double w;      // Weight
    double lambda; // Decay rate
    double density; // Initial value density (v/w)
} Item;

// Greedy priority function: items with higher decay rates and higher densities are prioritized
int compareItems(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    // Primary sort: Decay rate descending
    if (itemB->lambda != itemA->lambda) {
        return (itemB->lambda > itemA->lambda) ? 1 : -1;
    }
    // Secondary sort: Initial value density descending
    return (itemB->density > itemA->density) ? 1 : -1;
}

double solveDecayKnapsack(Item items[], int n, double W) {
    qsort(items, n, sizeof(Item), compareItems);

    double total_value = 0.0;
    double current_weight = 0.0;
    double current_time = 0.0;

    printf("Optimal Consumption Schedule:\n");
    for (int i = 0; i < n; i++) {
        if (current_weight >= W) break;

        double remaining_cap = W - current_weight;
        double take_weight = (items[i].w <= remaining_cap) ? items[i].w : remaining_cap;
        double fraction = take_weight / items[i].w;

        // Effective value density at time t: (v_i / w_i) - lambda_i * t
        double effective_density = items[i].density - (items[i].lambda * current_time);
        if (effective_density < 0) effective_density = 0; // Value density cannot be negative

        double value_gained = take_weight * effective_density;
        total_value += value_gained;

        printf("  Item %d: Fraction = %.2f, Time = %.2f, Effective Density = %.2f, Gained = %.2f\n",
               items[i].id, fraction, current_time, effective_density, value_gained);

        current_weight += take_weight;
        // Time elapses proportional to item weight consumed
        current_time += take_weight;
    }
    return total_value;
}

int main() {
    Item items[] = {
        {1, 60.0, 10.0, 0.05, 60.0 / 10.0},
        {2, 100.0, 20.0, 0.10, 100.0 / 20.0},
        {3, 120.0, 30.0, 0.02, 120.0 / 30.0}
    };
    int n = sizeof(items) / sizeof(items[0]);
    double W = 50.0;

    printf("--- QUESTION 1: FRACTIONAL KNAPSACK WITH DETERIORATION --- \n");
    double max_val = solveDecayKnapsack(items, n, W);
    printf("Total Maximized Value: %.2f\n", max_val);
    return 0;
}