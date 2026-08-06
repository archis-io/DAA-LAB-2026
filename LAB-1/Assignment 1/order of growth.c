#include <stdio.h>
#include <stdlib.h>

// Measure Search in Unsorted Array O(n)
long long search_unsorted(int arr[], int n, int key) {
    long long comps = 0;
    for (int i = 0; i < n; i++) {
        comps++;
        if (arr[i] == key) break;
    }
    return comps;
}

// Measure Search in Sorted Array O(log n)
long long search_sorted(int arr[], int n, int key) {
    long long comps = 0;
    int low = 0, high = n - 1;
    while (low <= high) {
        comps++;
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return comps;
        if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return comps;
}

int main() {
    int sizes[] = {1000, 5000, 10000, 50000, 100000};
    int num_sizes = 5;

    printf("--- Q1: Dictionary Search Order of Growth ---\n");
    printf("%-10s | %-25s | %-25s\n", "Size (N)", "Unsorted Array O(n)", "Sorted Array O(log n)");
    printf("----------------------------------------------------------------------\n");

    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        int *sorted_arr = (int *)malloc(n * sizeof(int));
        int *unsorted_arr = (int *)malloc(n * sizeof(int));

        for (int j = 0; j < n; j++) {
            sorted_arr[j] = j * 2;
            unsorted_arr[j] = rand() % (n * 2);
        }

        // Worst-case search (element not present)
        int target_key = -1; 
        long long lin_comps = search_unsorted(unsorted_arr, n, target_key);
        long long bin_comps = search_sorted(sorted_arr, n, target_key);

        printf("%-10d | %-25lld | %-25lld\n", n, lin_comps, bin_comps);

        free(sorted_arr);
        free(unsorted_arr);
    }
    return 0;
}