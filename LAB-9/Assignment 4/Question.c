#include <stdio.h>
#include <stdlib.h>

void minHeapify(int heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1, right = 2 * i + 2;
    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;
    if (smallest != i) {
        int temp = heap[i]; heap[i] = heap[smallest]; heap[smallest] = temp;
        minHeapify(heap, size, smallest);
    }
}

void pushHeap(int heap[], int *size, int val) {
    heap[*size] = val;
    int i = *size;
    (*size)++;
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        int temp = heap[i]; heap[i] = heap[(i - 1) / 2]; heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int popHeap(int heap[], int *size) {
    int root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    minHeapify(heap, *size, 0);
    return root;
}

int connectSticks(int sticks[], int n) {
    int heap[n];
    int heap_size = 0;
    for (int i = 0; i < n; i++) pushHeap(heap, &heap_size, sticks[i]);

    int total_cost = 0;
    while (heap_size > 1) {
        int first = popHeap(heap, &heap_size);
        int second = popHeap(heap, &heap_size);
        int cost = first + second;
        total_cost += cost;
        pushHeap(heap, &heap_size, cost);
    }
    return total_cost;
}

int main() {
    int sticks[] = {2, 4, 3, 8};
    int n = sizeof(sticks) / sizeof(sticks[0]);

    printf("--- QUESTION 4: MINIMUM COST TO CONNECT STICKS ---\n");
    printf("Minimum Connection Cost: %d\n", connectSticks(sticks, n));
    return 0;
}