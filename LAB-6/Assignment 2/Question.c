#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3

void matrix_addition(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) C[i][j] = A[i][j] + B[i][j];
}

void matrix_multiplication(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) C[i][j] += A[i][k] * B[k][j];
        }
    }
}

int is_zero_matrix(int A[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) if (A[i][j] != 0) return 0;
    return 1;
}

int is_symmetric_matrix(int A[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) if (A[i][j] != A[j][i]) return 0;
    return 1;
}

double compute_determinant(double mat[N][N]) {
    double det = 1.0;
    double temp[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) temp[i][j] = mat[i][j];

    for (int i = 0; i < N; i++) {
        int pivot = i;
        for (int j = i + 1; j < N; j++)
            if (fabs(temp[j][i]) > fabs(temp[pivot][i])) pivot = j;
        
        if (pivot != i) {
            for (int k = 0; k < N; k++) {
                double t = temp[i][k];
                temp[i][k] = temp[pivot][k];
                temp[pivot][k] = t;
            }
            det *= -1;
        }
        if (fabs(temp[i][i]) < 1e-9) return 0;
        det *= temp[i][i];
        for (int j = i + 1; j < N; j++) {
            double factor = temp[j][i] / temp[i][i];
            for (int k = i; k < N; k++) temp[j][k] -= factor * temp[i][k];
        }
    }
    return det;
}

void transpose_in_place(int A[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }
}

void power_iteration(double A[N][N]) {
    double x[N] = {1.0, 1.0, 1.0};
    double lambda = 0;
    for (int iter = 0; iter < 100; iter++) {
        double x_next[N] = {0};
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) x_next[i] += A[i][j] * x[j];
        
        lambda = fabs(x_next[0]);
        for (int i = 1; i < N; i++)
            if (fabs(x_next[i]) > lambda) lambda = fabs(x_next[i]);

        for (int i = 0; i < N; i++) x[i] = x_next[i] / lambda;
    }
    printf("Dominant Eigenvalue: %.4f\nEigenvector: [", lambda);
    for (int i = 0; i < N; i++) printf("%.4f ", x[i]);
    printf("]\n");
}

int main() {
    int A[N][N] = {{2, 1, 0}, {1, 3, 1}, {0, 1, 2}};
    int B[N][N] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int C[N][N];
    double A_dbl[N][N] = {{2, 1, 0}, {1, 3, 1}, {0, 1, 2}};

    printf("================ 2D MATRIX OPERATIONS ================\n");
    printf("Is Zero Matrix: %s\n", is_zero_matrix(A) ? "True" : "False");
    printf("Is Symmetric: %s\n", is_symmetric_matrix(A) ? "True" : "False");
    printf("Determinant: %.2f\n", compute_determinant(A_dbl));
    power_iteration(A_dbl);

    matrix_addition(A, B, C);
    printf("Matrix Addition A + B completed.\n");

    matrix_multiplication(A, B, C);
    printf("Matrix Multiplication A * B completed.\n");

    transpose_in_place(A);
    printf("In-place Transpose completed.\n");

    return 0;
}