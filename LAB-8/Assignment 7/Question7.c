#include <stdio.h>
#include <limits.h>

void rodCut(int price[], int n) {
    int val[n + 1];
    int parent[n + 1];
    val[0] = 0;

    for (int i = 1; i <= n; i++) {
        int max_val = INT_MIN;
        int best_cut = -1;
        for (int j = 0; j < i; j++) {
            if (price[j] + val[i - j - 1] > max_val) {
                max_val = price[j] + val[i - j - 1];
                best_cut = j + 1;
            }
        }
        val[i] = max_val;
        parent[i] = best_cut;
    }

    printf("Maximum Obtainable Revenue: %d\n", val[n]);
    printf("Optimal Piece Cuts: ");
    int temp = n;
    while (temp > 0) {
        printf("%d ", parent[temp]);
        temp -= parent[temp];
    }
    printf("\n");
}

int main() {
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(price) / sizeof(price[0]);

    printf("--- QUESTION 7: ROD CUTTING WITH RECONSTRUCTION ---\n");
    printf("Rod Length: %d\n", n);
    rodCut(price, n);
    return 0;
}