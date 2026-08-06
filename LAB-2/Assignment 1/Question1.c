#include <stdio.h>
#include <stdlib.h>

// Unsorted Array Search: O(n) worst case
int search_unsorted(int arr[], int n, int key) {
    int ops = 0;
    for (int i = 0; i < n; i++) {
        ops++;
        if (arr[i] == key) break;
    }
    return ops;
}

// Sorted Array Search (Binary Search): O(log n)
int search_sorted(int arr[], int n, int key) {
    int ops = 0, low = 0, high = n - 1;
    while (low <= high) {
        ops++;
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return ops;
        if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return ops;
}

int main() {
    int sizes[] = {1000, 5000, 10000, 50000};
    printf("=== Q1: Dictionary Search Comparisons ===\n");
    printf("%-10s | %-25s | %-25s\n", "Size (N)", "Unsorted Search Ops O(n)", "Sorted Search Ops O(log n)");
    printf("----------------------------------------------------------------------\n");

    for (int i = 0; i < 4; i++) {
        int n = sizes[i];
        int *sorted = (int *)malloc(n * sizeof(int));
        int *unsorted = (int *)malloc(n * sizeof(int));

        for (int j = 0; j < n; j++) {
            sorted[j] = j * 2;
            unsorted[j] = rand() % (n * 2);
        }

        int lin_ops = search_unsorted(unsorted, n, -1); // worst case search
        int bin_ops = search_sorted(sorted, n, -1);

        printf("%-10d | %-25d | %-25d\n", n, lin_ops, bin_ops);
        free(sorted); free(unsorted);
    }
    return 0;
}