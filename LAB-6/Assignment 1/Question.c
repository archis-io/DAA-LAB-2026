#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int find_max(int arr[], int n) {
    int max_val = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > max_val) max_val = arr[i];
    return max_val;
}

void find_first_second_max(int arr[], int n, int *first, int *second) {
    *first = (arr[0] > arr[1]) ? arr[0] : arr[1];
    *second = (arr[0] > arr[1]) ? arr[1] : arr[0];
    for (int i = 2; i < n; i++) {
        if (arr[i] > *first) {
            *second = *first;
            *first = arr[i];
        } else if (arr[i] > *second && arr[i] != *first) {
            *second = arr[i];
        }
    }
}

double find_mean(int arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    return sum / n;
}

int partition_qs(int arr[], int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) swap(&arr[++i], &arr[j]);
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

int quickselect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pi = partition_qs(arr, low, high);
        if (pi == k) return arr[pi];
        if (pi > k) return quickselect(arr, low, pi - 1, k);
        return quickselect(arr, pi + 1, high, k);
    }
    return -1;
}

double find_median(int arr[], int n) {
    int *temp = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) temp[i] = arr[i];
    double median;
    if (n % 2 != 0) {
        median = quickselect(temp, 0, n - 1, n / 2);
    } else {
        int m1 = quickselect(temp, 0, n - 1, n / 2);
        int m2 = quickselect(temp, 0, n - 1, n / 2 - 1);
        median = (m1 + m2) / 2.0;
    }
    free(temp);
    return median;
}

double find_std_dev(int arr[], int n, double mean) {
    double sum_sq = 0;
    for (int i = 0; i < n; i++) sum_sq += (arr[i] - mean) * (arr[i] - mean);
    return sqrt(sum_sq / n);
}

int compare_ints(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int find_mode(int arr[], int n) {
    int *temp = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) temp[i] = arr[i];
    qsort(temp, n, sizeof(int), compare_ints);
    int mode = temp[0], max_count = 1, curr_count = 1;
    for (int i = 1; i < n; i++) {
        if (temp[i] == temp[i - 1]) curr_count++;
        else {
            if (curr_count > max_count) {
                max_count = curr_count;
                mode = temp[i - 1];
            }
            curr_count = 1;
        }
    }
    if (curr_count > max_count) mode = temp[n - 1];
    free(temp);
    return mode;
}

int remove_duplicates(int arr[], int n) {
    if (n <= 1) return n;
    qsort(arr, n, sizeof(int), compare_ints);
    int j = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) arr[j++] = arr[i];
    }
    arr[j++] = arr[n - 1];
    return j;
}

void reverse_array(int arr[], int n) {
    int l = 0, r = n - 1;
    while (l < r) swap(&arr[l++], &arr[r--]);
}

void partition_around_pivot(int arr[], int n, int pivot_idx) {
    int pivot = arr[pivot_idx];
    swap(&arr[pivot_idx], &arr[n - 1]);
    int i = -1;
    for (int j = 0; j < n - 1; j++) {
        if (arr[j] >= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[n - 1]);
}

int main() {
    int arr[] = {12, 45, 12, 67, 89, 23, 45, 12, 90, 34};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("================ 1D ARRAY OPERATIONS ================\n");
    printf("Max Element: %d\n", find_max(arr, n));
    
    int first, second;
    find_first_second_max(arr, n, &first, &second);
    printf("1st & 2nd Max: %d, %d\n", first, second);

    double mean = find_mean(arr, n);
    printf("Mean: %.2f\n", mean);
    printf("Median: %.2f\n", find_median(arr, n));
    printf("Std Dev: %.2f\n", find_std_dev(arr, n, mean));
    printf("Mode: %d\n", find_mode(arr, n));

    reverse_array(arr, n);
    printf("Reversed Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    partition_around_pivot(arr, n, 3);
    printf("Partitioned Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    int new_sz = remove_duplicates(arr, n);
    printf("Unique Elements: ");
    for (int i = 0; i < new_sz; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}