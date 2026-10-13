#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculate maximum suffix-prefix overlap between string a and string b
int getOverlap(const char *a, const char *b) {
    int max_ov = 0;
    int len_a = strlen(a);
    int len_b = strlen(b);
    int min_len = (len_a < len_b) ? len_a : len_b;

    for (int k = 1; k <= min_len; k++) {
        if (strncmp(a + len_a - k, b, k) == 0) {
            max_ov = k;
        }
    }
    return max_ov;
}

void greedySuperstring(char *s[], int n) {
    char *arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = strdup(s[i]);
    }

    int active_count = n;
    while (active_count > 1) {
        int max_overlap = -1;
        int idx1 = -1, idx2 = -1;

        for (int i = 0; i < active_count; i++) {
            for (int j = 0; j < active_count; j++) {
                if (i != j) {
                    int ov = getOverlap(arr[i], arr[j]);
                    if (ov > max_overlap) {
                        max_overlap = ov;
                        idx1 = i;
                        idx2 = j;
                    }
                }
            }
        }

        // Merge arr[idx1] and arr[idx2]
        int len1 = strlen(arr[idx1]);
        int len2 = strlen(arr[idx2]);
        char *merged = (char *)malloc(len1 + len2 - max_overlap + 1);
        strcpy(merged, arr[idx1]);
        strcat(merged, arr[idx2] + max_overlap);

        free(arr[idx1]);
        free(arr[idx2]);
        arr[idx1] = merged;

        arr[idx2] = arr[active_count - 1];
        active_count--;
    }

    printf("--- QUESTION 10: GREEDY SUPERSTRING CONJECTURE ---\n");
    printf("Resulting Shortest Superstring: %s\n", arr[0]);
    printf("Length: %lu\n", strlen(arr[0]));
    free(arr[0]);
}

int main() {
    char *strings[] = {"CATGC", "CTAAGT", "GCTA", "TTCA", "ATGCATC"};
    int n = sizeof(strings) / sizeof(strings[0]);

    greedySuperstring(strings, n);
    return 0;
}