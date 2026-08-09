#include <stdio.h>

// Binary search approach: O(log n)
int find_partition_point(int arr[], int n) {
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == 1) {
            ans = mid;     // Transition point candidate
            high = mid - 1; // Look left for first '1'
        } else {
            low = mid + 1;  // Look right
        }
    }
    return ans;
}

int main() {
    int arr[] = {0, 0, 0, 0, 0, 1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Input Array: [ ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("]\n");

    int index = find_partition_point(arr, n);

    if (index != -1) {
        printf("Transition from 0 to 1 happens at index: %d\n", index);
    } else {
        printf("No transition point found (Array contains only 0s).\n");
    }

    return 0;
}