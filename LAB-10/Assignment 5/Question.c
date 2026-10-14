#include <stdio.h>
#include <stdlib.h>

int parent[1005];

int find(int i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

void unionSets(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    if (root_u != root_v) parent[root_u] = root_v;
}

int compareInts(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void smallestPermutation(int A[], int n, int swaps[][2], int m) {
    for (int i = 0; i < n; i++) parent[i] = i;

    for (int i = 0; i < m; i++) {
        unionSets(swaps[i][0], swaps[i][1]);
    }

    int comp_indices[1005][1005];
    int comp_values[1005][1005];
    int comp_size[1005] = {0};

    for (int i = 0; i < n; i++) {
        int root = find(i);
        int idx = comp_size[root];
        comp_indices[root][idx] = i;
        comp_values[root][idx] = A[i];
        comp_size[root]++;
    }

    int result[n];
    for (int i = 0; i < n; i++) {
        if (comp_size[i] > 0) {
            qsort(comp_indices[i], comp_size[i], sizeof(int), compareInts);
            qsort(comp_values[i], comp_size[i], sizeof(int), compareInts);

            for (int k = 0; k < comp_size[i]; k++) {
                result[comp_indices[i][k]] = comp_values[i][k];
            }
        }
    }

    printf("Lexicographically Smallest Permutation: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

int main() {
    int A[] = {5, 3, 1, 4, 2};
    int n = sizeof(A) / sizeof(A[0]);

    // Allowed pairwise index swaps (0-indexed)
    int swaps[][2] = {{0, 2}, {1, 2}, {3, 4}};
    int m = sizeof(swaps) / sizeof(swaps[0]);

    printf("--- QUESTION 5: LEXICOGRAPHICALLY SMALLEST PERMUTATION ---\n");
    smallestPermutation(A, n, swaps, m);
    return 0;
}