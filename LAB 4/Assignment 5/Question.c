#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int compare(const void *a, const void *b) {
    return ((Interval *)a)->start - ((Interval *)b)->start;
}

int main() {
    Interval I[] = {{1, 3}, {2, 6}, {8, 10}, {7, 18}};
    int n = sizeof(I) / sizeof(I[0]);

    qsort(I, n, sizeof(Interval), compare); // O(n log n)

    Interval merged[n];
    int count = 0;
    merged[0] = I[0];

    for (int i = 1; i < n; i++) {
        if (I[i].start <= merged[count].end) {
            if (I[i].end > merged[count].end) {
                merged[count].end = I[i].end;
            }
        } else {
            count++;
            merged[count] = I[i];
        }
    }

    printf("Merged Intervals:\n");
    for (int i = 0; i <= count; i++) {
        printf("(%d, %d) ", merged[i].start, merged[i].end);
    }
    printf("\n");
    return 0;
}