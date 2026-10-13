#include <stdio.h>
#include <stdlib.h>

void maxHeapify(int heap[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1, right = 2 * i + 2;
    if (left < size && heap[left] > heap[largest]) largest = left;
    if (right < size && heap[right] > heap[largest]) largest = right;
    if (largest != i) {
        int temp = heap[i]; heap[i] = heap[largest]; heap[largest] = temp;
        maxHeapify(heap, size, largest);
    }
}

void pushHeap(int heap[], int *size, int val) {
    heap[*size] = val;
    int i = *size;
    (*size)++;
    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        int temp = heap[i]; heap[i] = heap[(i - 1) / 2]; heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int popHeap(int heap[], int *size) {
    int root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    maxHeapify(heap, *size, 0);
    return root;
}

int minimumDeviation(int nums[], int n) {
    int max_heap[n];
    int heap_size = 0;
    int min_val = 1e9;

    // Double odd numbers, track initial minimum
    for (int i = 0; i < n; i++) {
        int val = (nums[i] % 2 != 0) ? nums[i] * 2 : nums[i];
        pushHeap(max_heap, &heap_size, val);
        if (val < min_val) min_val = val;
    }

    int min_dev = 1e9;
    while (1) {
        int max_val = popHeap(max_heap, &heap_size);
        int dev = max_val - min_val;
        if (dev < min_dev) min_dev = dev;

        // If maximum element is odd, division operation terminates
        if (max_val % 2 != 0) break;

        max_val /= 2;
        if (max_val < min_val) min_val = max_val;
        pushHeap(max_heap, &heap_size, max_val);
    }
    return min_dev;
}

int main() {
    int nums[] = {1, 2, 3, 4};
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("--- QUESTION 7: MINIMIZE DEVIATION IN ARRAY ---\n");
    printf("Minimum Deviation: %d\n", minimumDeviation(nums, n));
    return 0;
}