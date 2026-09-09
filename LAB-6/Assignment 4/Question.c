#include <stdio.h>
#include <stdlib.h>

int total_cost = 0;
int total_reversals = 0;

void reverse(int p[], int i, int j) {
    if (i >= j) return;
    int len = j - i + 1;
    total_cost += len;
    total_reversals++;
    while (i < j) {
        int temp = p[i];
        p[i] = p[j];
        p[j] = temp;
        i++; j--;
    }
}

void sort_by_reversals(int p[], int n) {
    for (int i = 0; i < n; i++) {
        int target = i + 1;
        int idx = -1;
        for (int j = i; j < n; j++) {
            if (p[j] == target) {
                idx = j;
                break;
            }
        }
        if (idx != i) reverse(p, i, idx);
    }
}

int main() {
    int p[] = {1, 4, 3, 2, 5};
    int n = sizeof(p) / sizeof(p[0]);

    printf("================ SORTING VIA REVERSAL PROCEDURE ================\n");
    printf("Original Permutation: ");
    for (int i = 0; i < n; i++) printf("%d ", p[i]);
    printf("\n");

    sort_by_reversals(p, n);

    printf("Sorted Permutation:   ");
    for (int i = 0; i < n; i++) printf("%d ", p[i]);
    printf("\n\nTotal Reversals: %d (Bounded by O(n))\nTotal Cost:      %d (Bounded by O(n log^2 n))\n", total_reversals, total_cost);

    return 0;
}