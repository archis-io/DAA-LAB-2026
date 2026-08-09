#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Method 1: Brute Force O(n^2)
int check_unique_brute(int arr[], int n, long *comparisons) {
    *comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            (*comparisons)++;
            if (arr[i] == arr[j]) return 0; // Duplicate found
        }
    }
    return 1; // All unique
}

int main() {
    srand(time(NULL));
    int sizes[] = {100, 500, 1000, 5000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("Array Size\tComparisons (Brute Force)\tUniqueness Result\n");
    printf("-----------------------------------------------------------------\n");

    for (int k = 0; k < num_sizes; k++) {
        int n = sizes[k];
        int *arr = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            arr[i] = rand() % (n * 10); // Random numbers
        }

        long comparisons = 0;
        int unique = check_unique_brute(arr, n, &comparisons);

        printf("%-10d\t%-27ld\t%s\n", n, comparisons, unique ? "Unique" : "Duplicates Found");
        free(arr);
    }

    printf("\nConclusion: For large n, Brute Force O(n^2) scales poorly. Sorting-based method O(n log n) is superior.\n");
    return 0;
}