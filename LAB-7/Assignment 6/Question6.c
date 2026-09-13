#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int year;
    int type; // -1 for death, +1 for birth (death processed first if same year)
} Event;

int compare_events(const void *a, const void *b) {
    Event *e1 = (Event *)a;
    Event *e2 = (Event *)b;
    if (e1->year != e2->year) return e1->year - e2->year;
    return e1->type - e2->type;
}

int main() {
    int birth[] = {1879, 1642, 1856, 1867};
    int death[] = {1955, 1727, 1943, 1934};
    int m = 4;

    Event events[2 * m];
    for (int i = 0; i < m; i++) {
        events[2 * i] = (Event){birth[i], 1};
        events[2 * i + 1] = (Event){death[i], -1};
    }

    qsort(events, 2 * m, sizeof(Event), compare_events);

    int max_alive = 0, current_alive = 0, peak_year = 0;
    for (int i = 0; i < 2 * m; i++) {
        current_alive += events[i].type;
        if (current_alive > max_alive) {
            max_alive = current_alive;
            peak_year = events[i].year;
        }
    }

    printf("--- QUESTION 6: THE BEST TIME TO BE ALIVE ---\n");
    printf("Max Scientists Alive Simultaneously: %d\n", max_alive);
    printf("Peak Year: %d\n", peak_year);
    return 0;
}