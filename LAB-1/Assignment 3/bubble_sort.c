#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Version (i): Optimized with Early Termination Flag
long bubble_sort_optimized(int arr[], int n) {
    long comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
    return comparisons;
}

// Version (ii): Always Completes (n - 1) Passes
long bubble_sort_standard(int arr[], int n) {
    long comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return comparisons;
}

int main() {
    srand(time(NULL));
    int sizes[] = {100, 200, 500, 1000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("Array Size\tOptimized Comparisons\tStandard Comparisons\n");
    printf("-------------------------------------------------------------\n");

    for (int k = 0; k < num_sizes; k++) {
        int n = sizes[k];
        int *a1 = malloc(n * sizeof(int));
        int *a2 = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            int val = rand() % 10000;
            a1[i] = val;
            a2[i] = val;
        }

        long comp_opt = bubble_sort_optimized(a1, n);
        long comp_std = bubble_sort_standard(a2, n);

        printf("%-10d\t%-22ld\t%-20ld\n", n, comp_opt, comp_std);

        free(a1);
        free(a2);
    }

    return 0;
}