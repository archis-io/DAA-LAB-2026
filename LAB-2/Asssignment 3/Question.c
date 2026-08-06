#include <stdio.h>
#include <stdlib.h>

long long ops_m1 = 0, ops_m2 = 0;

void merge2(int a[], int sa, int b[], int sb, int res[], int mode) {
    int i = 0, j = 0, k = 0;
    while (i < sa && j < sb) {
        if (mode == 1) ops_m1++; else ops_m2++;
        res[k++] = (a[i] <= b[j]) ? a[i++] : b[j++];
    }
    while (i < sa) res[k++] = a[i++];
    while (j < sb) res[k++] = b[j++];
}

void method1_sequential(int **arrays, int k, int n, int *res) {
    int *curr = (int*)malloc(n * sizeof(int));
    for (int j = 0; j < n; j++) curr[j] = arrays[0][j];
    int curr_sz = n;

    for (int i = 1; i < k; i++) {
        int *temp = (int*)malloc((curr_sz + n) * sizeof(int));
        merge2(curr, curr_sz, arrays[i], n, temp, 1);
        free(curr);
        curr = temp;
        curr_sz += n;
    }
    for (int j = 0; j < curr_sz; j++) res[j] = curr[j];
    free(curr);
}

void method2_pairwise(int **arrays, int k, int n, int *res) {
    int **arrs = (int**)malloc(k * sizeof(int*));
    int *sz = (int*)malloc(k * sizeof(int));

    for (int i = 0; i < k; i++) {
        arrs[i] = (int*)malloc(n * sizeof(int));
        sz[i] = n;
        for (int j = 0; j < n; j++) arrs[i][j] = arrays[i][j];
    }

    int active = k;
    while (active > 1) {
        int next_k = (active + 1) / 2;
        int **next_arrs = (int**)malloc(next_k * sizeof(int*));
        int *next_sz = (int*)malloc(next_k * sizeof(int));

        int idx = 0;
        for (int i = 0; i < active; i += 2) {
            if (i + 1 < active) {
                int out_sz = sz[i] + sz[i+1];
                next_arrs[idx] = (int*)malloc(out_sz * sizeof(int));
                next_sz[idx] = out_sz;
                merge2(arrs[i], sz[i], arrs[i+1], sz[i+1], next_arrs[idx], 2);
                free(arrs[i]); free(arrs[i+1]);
            } else {
                next_arrs[idx] = arrs[i];
                next_sz[idx] = sz[i];
            }
            idx++;
        }
        free(arrs); free(sz);
        arrs = next_arrs; sz = next_sz; active = next_k;
    }
    for (int j = 0; j < sz[0]; j++) res[j] = arrs[0][j];
    free(arrs[0]); free(arrs); free(sz);
}

int main() {
    int k_vals[] = {4, 8, 16, 32};
    int n = 1000;
    printf("=== Q3: Merging k Sorted Arrays (n = 1000) ===\n");
    printf("%-10s | %-25s | %-25s\n", "k Arrays", "Sequential Ops O(n*k^2)", "Pairwise Ops O(n*k log k)");
    printf("-------------------------------------------------------------------------\n");

    for (int idx = 0; idx < 4; idx++) {
        int k = k_vals[idx];
        int **arrays = (int**)malloc(k * sizeof(int*));
        for (int i = 0; i < k; i++) {
            arrays[i] = (int*)malloc(n * sizeof(int));
            for (int j = 0; j < n; j++) arrays[i][j] = j * (i + 1);
        }

        int *r1 = (int*)malloc(k * n * sizeof(int));
        int *r2 = (int*)malloc(k * n * sizeof(int));
        ops_m1 = 0; ops_m2 = 0;

        method1_sequential(arrays, k, n, r1);
        method2_pairwise(arrays, k, n, r2);

        printf("%-10d | %-25lld | %-25lld\n", k, ops_m1, ops_m2);

        for (int i = 0; i < k; i++) free(arrays[i]);
        free(arrays); free(r1); free(r2);
    }
    return 0;
}