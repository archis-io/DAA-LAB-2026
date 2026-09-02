#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

int find_kth_smallest(int arr[], int low, int high, int k_index) {
    if (low <= high) {
        int pivot_index = partition(arr, low, high);

        if (pivot_index == k_index)
            return arr[pivot_index];
        else if (pivot_index > k_index)
            return find_kth_smallest(arr, low, pivot_index - 1, k_index);
        else
            return find_kth_smallest(arr, pivot_index + 1, high, k_index);
    }
    return -1;
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; // Find 3rd smallest element

    int result = find_kth_smallest(arr, 0, n - 1, k - 1);
    printf("%d-th smallest element is: %d\n", k, result);
    return 0;
}