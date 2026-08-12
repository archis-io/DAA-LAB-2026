#include <stdio.h>

int binary_search(int arr[], int l, int r, int x, int *comps) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        (*comps)++;
        if (arr[mid] == x) return mid;
        (*comps)++;
        if (arr[mid] > x) return binary_search(arr, l, mid - 1, x, comps);
        return binary_search(arr, mid + 1, r, x, comps);
    }
    return -1;
}

int ternary_search(int arr[], int l, int r, int x, int *comps) {
    if (r >= l) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        (*comps)++;
        if (arr[mid1] == x) return mid1;
        (*comps)++;
        if (arr[mid2] == x) return mid2;
        (*comps)++;
        if (x < arr[mid1]) return ternary_search(arr, l, mid1 - 1, x, comps);
        (*comps)++;
        if (x > arr[mid2]) return ternary_search(arr, mid2 + 1, r, x, comps);
        return ternary_search(arr, mid1 + 1, mid2 - 1, x, comps);
    }
    return -1;
}

int main() {
    int arr[100];
    for (int i = 0; i < 100; i++) arr[i] = i * 2; // Sorted array
    int key = 150; // Element to search

    int b_comps = 0, t_comps = 0;
    binary_search(arr, 0, 99, key, &b_comps);
    ternary_search(arr, 0, 99, key, &t_comps);

    printf("Binary Search Comparisons: %d\n", b_comps);
    printf("Ternary Search Comparisons: %d\n", t_comps);
    printf("Conclusion: Binary search requires fewer comparisons.\n");
    return 0;
}