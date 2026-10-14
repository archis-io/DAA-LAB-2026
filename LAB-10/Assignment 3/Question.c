#include <stdio.h>

int parent[1005];
int size_comp[1005];
int weight_comp[1005];

int find(int i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

void unionSets(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    if (root_u != root_v) {
        parent[root_u] = root_v;
        size_comp[root_v] += size_comp[root_u];
        weight_comp[root_v] += weight_comp[root_u];
    }
}

int getMaxWeightSizeK(int V, int K) {
    int max_weight = 0;
    for (int i = 1; i <= V; i++) {
        if (parent[i] == i && size_comp[i] <= K) {
            if (weight_comp[i] > max_weight) {
                max_weight = weight_comp[i];
            }
        }
    }
    return max_weight;
}

int main() {
    int V = 5;
    int K = 3;
    int initial_weights[] = {0, 10, 20, 15, 30, 25};

    for (int i = 1; i <= V; i++) {
        parent[i] = i;
        size_comp[i] = 1;
        weight_comp[i] = initial_weights[i];
    }

    printf("--- QUESTION 3: MAX WEIGHT COMPONENT WITH SIZE CONSTRAINTS ---\n");
    printf("Initial Max Weight (Size <= %d): %d\n", K, getMaxWeightSizeK(V, K));

    unionSets(1, 2);
    printf("After adding Edge (1, 2) -> Max Weight (Size <= %d): %d\n", K, getMaxWeightSizeK(V, K));

    unionSets(2, 3);
    printf("After adding Edge (2, 3) -> Max Weight (Size <= %d): %d\n", K, getMaxWeightSizeK(V, K));

    unionSets(3, 4); // Component size becomes 4 > K=3
    printf("After adding Edge (3, 4) -> Max Weight (Size <= %d): %d\n", K, getMaxWeightSizeK(V, K));

    return 0;
}