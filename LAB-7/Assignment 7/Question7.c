#include <stdio.h>
#include <limits.h>

void print_optimal_parens(int i, int j, int n, int *s) {
    if (i == j) {
        printf("A%d", i);
        return;
    }
    printf("(");
    print_optimal_parens(i, *((s + i * n) + j), n, s);
    print_optimal_parens(*((s + i * n) + j) + 1, j, n, s);
    printf(")");
}

void matrix_chain_order(int p[], int n) {
    int m[n][n];
    int s[n][n];

    for (int i = 1; i < n; i++) m[i][i] = 0;

    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("Minimum Scalar Multiplications: %d\n", m[1][n - 1]);
    printf("Optimal Parenthesization: ");
    print_optimal_parens(1, n - 1, n, (int *)s);
    printf("\n");
}

int main() {
    int arr[] = {40, 20, 30, 10, 30};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("--- QUESTION 7: MATRIX CHAIN MULTIPLICATION ---\n");
    matrix_chain_order(arr, size);
    return 0;
}