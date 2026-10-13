#include <stdio.h>
#include <stdlib.h>

int compareInts(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minMeetingRooms(int intervals[][2], int n) {
    int starts[n];
    int ends[n];
    for (int i = 0; i < n; i++) {
        starts[i] = intervals[i][0];
        ends[i] = intervals[i][1];
    }

    qsort(starts, n, sizeof(int), compareInts);
    qsort(ends, n, sizeof(int), compareInts);

    int rooms = 0, max_rooms = 0;
    int start_ptr = 0, end_ptr = 0;

    while (start_ptr < n) {
        if (starts[start_ptr] < ends[end_ptr]) {
            rooms++;
            if (rooms > max_rooms) max_rooms = rooms;
            start_ptr++;
        } else {
            rooms--;
            end_ptr++;
        }
    }
    return max_rooms;
}

int main() {
    int intervals[][2] = {{0, 30}, {5, 10}, {15, 20}};
    int n = sizeof(intervals) / sizeof(intervals[0]);

    printf("--- QUESTION 8: MINIMUM MEETING ROOMS ---\n");
    printf("Minimum Meeting Rooms Needed: %d\n", minMeetingRooms(intervals, n));
    return 0;
}