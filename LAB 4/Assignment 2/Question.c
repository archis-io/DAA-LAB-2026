#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int binary_search(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return 1;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return 0;
}

int main() {
    int S1[] = {3, 10, 4, 15};
    int S2[] = {7, 2, 8, 1};
    int n = 4, x = 12;

    qsort(S2, n, sizeof(int), compare); // O(n log n)

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (binary_search(S2, n, x - S1[i])) { // O(log n)
            printf("Pair found: %d from S1 and %d from S2 (Sum = %d)\n", S1[i], x - S1[i], x);
            found = 1;
            break;
        }
    }
    if (!found) printf("No pair found.\n");
    return 0;
}