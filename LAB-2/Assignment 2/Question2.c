#include <stdio.h>
#include <stdlib.h>

long long ops_2way = 0, ops_3way = 0;

void merge2(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        ops_2way++;
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    free(L); free(R);
}

void mergeSort2(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort2(arr, l, m);
        mergeSort2(arr, m + 1, r);
        merge2(arr, l, m, r);
    }
}

void merge3(int arr[], int l, int m1, int m2, int r) {
    int n1 = m1 - l + 1, n2 = m2 - m1, n3 = r - m2;
    int *L = (int*)malloc(n1 * sizeof(int));
    int *M = (int*)malloc(n2 * sizeof(int));
    int *R = (int*)malloc(n3 * sizeof(int));
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) M[i] = arr[m1 + 1 + i];
    for (int i = 0; i < n3; i++) R[i] = arr[m2 + 1 + i];

    int i = 0, j = 0, k = 0, idx = l;
    while (i < n1 && j < n2 && k < n3) {
        ops_3way += 2;
        if (L[i] <= M[j] && L[i] <= R[k]) arr[idx++] = L[i++];
        else if (M[j] <= L[i] && M[j] <= R[k]) arr[idx++] = M[j++];
        else arr[idx++] = R[k++];
    }
    while (i < n1 && j < n2) { ops_3way++; arr[idx++] = (L[i] <= M[j]) ? L[i++] : M[j++]; }
    while (j < n2 && k < n3) { ops_3way++; arr[idx++] = (M[j] <= R[k]) ? M[j++] : R[k++]; }
    while (i < n1 && k < n3) { ops_3way++; arr[idx++] = (L[i] <= R[k]) ? L[i++] : R[k++]; }
    while (i < n1) arr[idx++] = L[i++];
    while (j < n2) arr[idx++] = M[j++];
    while (k < n3) arr[idx++] = R[k++];
    free(L); free(M); free(R);
}

void mergeSort3(int arr[], int l, int r) {
    if (l < r) {
        if (r - l < 2) {
            ops_3way++;
            if (arr[l] > arr[r]) { int t = arr[l]; arr[l] = arr[r]; arr[r] = t; }
            return;
        }
        int m1 = l + (r - l) / 3;
        int m2 = l + 2 * (r - l) / 3;
        mergeSort3(arr, l, m1);
        mergeSort3(arr, m1 + 1, m2);
        mergeSort3(arr, m2 + 1, r);
        merge3(arr, l, m1, m2, r);
    }
}

int main() {
    int sizes[] = {1000, 5000, 10000, 50000};
    printf("=== Q2: Merge Sort vs 3-Way Merge Sort ===\n");
    printf("%-10s | %-22s | %-22s\n", "Size (N)", "2-Way Comparisons", "3-Way Comparisons");
    printf("-----------------------------------------------------------------\n");

    for (int i = 0; i < 4; i++) {
        int n = sizes[i];
        int *a1 = (int*)malloc(n * sizeof(int));
        int *a2 = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) { int v = rand() % 10000; a1[j] = v; a2[j] = v; }

        ops_2way = 0; ops_3way = 0;
        mergeSort2(a1, 0, n - 1);
        mergeSort3(a2, 0, n - 1);

        printf("%-10d | %-22lld | %-22lld\n", n, ops_2way, ops_3way);
        free(a1); free(a2);
    }
    return 0;
}