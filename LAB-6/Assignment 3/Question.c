#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double real;
    double imag;
} Complex;

Complex add_c(Complex a, Complex b) { return (Complex){a.real + b.real, a.imag + b.imag}; }
Complex sub_c(Complex a, Complex b) { return (Complex){a.real - b.real, a.imag - b.imag}; }
Complex mul_c(Complex a, Complex b) {
    return (Complex){a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real};
}

void fft(Complex *X, int N, int invert) {
    if (N <= 1) return;
    Complex *even = (Complex *)malloc((N / 2) * sizeof(Complex));
    Complex *odd = (Complex *)malloc((N / 2) * sizeof(Complex));

    for (int i = 0; i < N / 2; i++) {
        even[i] = X[2 * i];
        odd[i] = X[2 * i + 1];
    }

    fft(even, N / 2, invert);
    fft(odd, N / 2, invert);

    double angle = 2 * PI / N * (invert ? -1 : 1);
    Complex w = {1, 0}, w1 = {cos(angle), sin(angle)};
    for (int i = 0; i < N / 2; i++) {
        Complex t = mul_c(w, odd[i]);
        X[i] = add_c(even[i], t);
        X[i + N / 2] = sub_c(even[i], t);
        if (invert) {
            X[i].real /= 2; X[i].imag /= 2;
            X[i + N / 2].real /= 2; X[i + N / 2].imag /= 2;
        }
        w = mul_c(w, w1);
    }
    free(even);
    free(odd);
}

int main() {
    double A[] = {1, 2, 3};
    double B[] = {4, 5, 6, 7};
    int m = 3, n = 4;
    int size = m + n - 1;

    int N = 1;
    while (N < size) N <<= 1;

    Complex *ca = (Complex *)calloc(N, sizeof(Complex));
    Complex *cb = (Complex *)calloc(N, sizeof(Complex));

    for (int i = 0; i < m; i++) ca[i].real = A[i];
    for (int i = 0; i < n; i++) cb[i].real = B[i];

    fft(ca, N, 0);
    fft(cb, N, 0);

    Complex *cc = (Complex *)malloc(N * sizeof(Complex));
    for (int i = 0; i < N; i++) cc[i] = mul_c(ca[i], cb[i]);

    fft(cc, N, 1);

    printf("================ VECTOR CONVOLUTION O(n log n) ================\n");
    printf("Convolution Result C[k]: ");
    for (int i = 0; i < size; i++) printf("%.1f ", cc[i].real);
    printf("\n");

    free(ca); free(cb); free(cc);
    return 0;
}