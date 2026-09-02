#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void generate_random_file(const char *filename, int n) {
    FILE *fp = fopen(filename, "w");
    if (!fp) return;
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", rand() % 10000);
    }
    fclose(fp);
}

int main() {
    int n = 100;
    const char *infile = "input_quick.txt";
    const char *outfile = "output_quick.txt";

    generate_random_file(infile, n);

    FILE *fin = fopen(infile, "r");
    if (!fin) return 1;

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        fscanf(fin, "%d", &arr[i]);
    }
    fclose(fin);

    quick_sort(arr, 0, n - 1);

    FILE *fout = fopen(outfile, "w");
    for (int i = 0; i < n; i++) {
        fprintf(fout, "%d\n", arr[i]);
    }
    fclose(fout);
    free(arr);

    printf("Successfully sorted %d elements from '%s' to '%s'.\n", n, infile, outfile);
    return 0;
}