#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) {
    // Step 1: Build Max-Heap O(N)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: Extract elements one by one O(N log N)
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
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
    const char *infile = "input_heap.txt";
    const char *outfile = "output_heap.txt";

    generate_random_file(infile, n);

    FILE *fin = fopen(infile, "r");
    if (!fin) return 1;

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        fscanf(fin, "%d", &arr[i]);
    }
    fclose(fin);

    heap_sort(arr, n);

    FILE *fout = fopen(outfile, "w");
    for (int i = 0; i < n; i++) {
        fprintf(fout, "%d\n", arr[i]);
    }
    fclose(fout);
    free(arr);

    printf("Successfully sorted %d elements using HeapSort from '%s' to '%s'.\n", n, infile, outfile);
    return 0;
}