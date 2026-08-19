#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int coord;
    int type; // +1 for start, -1 for end
} PointEvent;

int compare(const void *a, const void *b) {
    PointEvent *p1 = (PointEvent *)a;
    PointEvent *p2 = (PointEvent *)b;
    if (p1->coord != p2->coord) return p1->coord - p2->coord;
    return p2->type - p1->type; // Start (+1) before End (-1) if tied
}

int main() {
    int l[] = {10, 20, 50, 15};
    int r[] = {40, 60, 90, 70};
    int n = 4;

    PointEvent events[2 * n];
    for (int i = 0; i < n; i++) {
        events[2 * i] = (PointEvent){l[i], 1};
        events[2 * i + 1] = (PointEvent){r[i], -1};
    }

    qsort(events, 2 * n, sizeof(PointEvent), compare); // O(n log n)

    int active = 0, max_intervals = 0, best_point = -1;
    for (int i = 0; i < 2 * n; i++) {
        active += events[i].type;
        if (active > max_intervals) {
            max_intervals = active;
            best_point = events[i].coord;
        }
    }

    printf("Point in most intervals: p = %d (present in %d intervals)\n", best_point, max_intervals);
    return 0;
}