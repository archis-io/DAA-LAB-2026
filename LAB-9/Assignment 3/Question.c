#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dist;
    int fuel;
} Station;

int compareStations(const void* a, const void* b) {
    return ((Station*)a)->dist - ((Station*)b)->dist;
}

// Max-heap logic for reachable station fuels
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
    if (*size <= 0) return -1;
    int root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    maxHeapify(heap, *size, 0);
    return root;
}

int minRefuelStops(int target, int startFuel, Station stations[], int n) {
    qsort(stations, n, sizeof(Station), compareStations);

    int max_heap[n + 1];
    int heap_size = 0;
    int curr_fuel = startFuel;
    int stops = 0, i = 0;

    while (curr_fuel < target) {
        while (i < n && stations[i].dist <= curr_fuel) {
            pushHeap(max_heap, &heap_size, stations[i].fuel);
            i++;
        }
        if (heap_size == 0) return -1; // Unreachable target
        curr_fuel += popHeap(max_heap, &heap_size);
        stops++;
    }
    return stops;
}

int main() {
    int target = 100;
    int startFuel = 10;
    Station stations[] = {{10, 60}, {20, 30}, {30, 30}, {60, 40}};
    int n = sizeof(stations) / sizeof(stations[0]);

    printf("--- QUESTION 3: MINIMUM REFUELING STOPS ---\n");
    int stops = minRefuelStops(target, startFuel, stations, n);
    printf("Target: %d | Start Fuel: %d\n", target, startFuel);
    printf("Minimum Refuel Stops Needed: %d\n", stops);
    return 0;
}