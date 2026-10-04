#include <stdio.h>

int lis(int arr[], int n) {
    int lis[n];
    for (int i = 0; i < n; i++) lis[i] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        if (max < lis[i]) max = lis[i];
    }
    return max;
}

int main() {
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("--- QUESTION 4: LONGEST INCREASING SUBSEQUENCE ---\n");
    printf("Length of LIS: %d\n", lis(arr, n));
    return 0;
}