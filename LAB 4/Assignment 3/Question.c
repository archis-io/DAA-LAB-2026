#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int binary_search(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// k-Sum implementation for k=3 (O(n^(k-1) log n) = O(n^2 log n))
int three_sum(int arr[], int n, int T) {
    qsort(arr, n, sizeof(int), compare);

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int rem = T - (arr[i] + arr[j]);
            int idx = binary_search(arr, j + 1, n - 1, rem);
            if (idx != -1) {
                printf("Elements found: %d, %d, %d (Sum = %d)\n", arr[i], arr[j], arr[idx], T);
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int S[] = {1, 4, 45, 6, 10, 8};
    int n = sizeof(S) / sizeof(S[0]);
    int T = 22;

    if (!three_sum(S, n, T)) printf("No 3 elements sum to %d\n", T);
    return 0;
}