#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int time;
    int type; // +1 for entry, -1 for exit
} Event;

int compare(const void *a, const void *b) {
    Event *e1 = (Event *)a;
    Event *e2 = (Event *)b;
    if (e1->time != e2->time) return e1->time - e2->time;
    return e1->type - e2->type; // Exits before entries if same time
}

int main() {
    int a[] = {1, 2, 9, 5, 8}; // Entry times
    int b[] = {4, 5, 12, 9, 10}; // Exit times
    int n = 5;

    Event events[2 * n];
    for (int i = 0; i < n; i++) {
        events[2 * i] = (Event){a[i], 1};
        events[2 * i + 1] = (Event){b[i], -1};
    }

    qsort(events, 2 * n, sizeof(Event), compare); // O(n log n)

    int current_people = 0, max_people = 0, best_time = -1;
    for (int i = 0; i < 2 * n; i++) {
        current_people += events[i].type;
        if (current_people > max_people) {
            max_people = current_people;
            best_time = events[i].time;
        }
    }

    printf("Max people simultaneously present: %d at time %d\n", max_people, best_time);
    return 0;
}