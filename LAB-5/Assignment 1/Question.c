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

int quick_select(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pivot_index = partition(arr, low, high);

        if (pivot_index == k)
            return arr[pivot_index];
        else if (pivot_index > k)
            return quick_select(arr, low, pivot_index - 1, k);
        else
            return quick_select(arr, pivot_index + 1, high, k);
    }
    return -1;
}

int main() {
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr) / sizeof(arr[0]);
    int median_idx = n / 2;

    int median = quick_select(arr, 0, n - 1, median_idx);
    printf("Median of the array: %d\n", median);
    return 0;
}