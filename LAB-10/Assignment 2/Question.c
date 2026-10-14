#include <stdio.h>
#include <stdlib.h>

int parent[10000];
int R, C;

int find(int i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

int unionSets(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);
    if (root_i != root_j) {
        parent[root_i] = root_j;
        return 1;
    }
    return 0;
}

void numIslands2(int r, int c, int positions[][2], int k) {
    R = r; C = c;
    for (int i = 0; i < R * C; i++) parent[i] = -1;

    int island_count = 0;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    printf("Island count updates:\n");
    for (int p = 0; p < k; p++) {
        int row = positions[p][0];
        int col = positions[p][1];
        int idx = row * C + col;

        if (parent[idx] != -1) {
            printf("  Step %d: (%d, %d) already land -> Islands: %d\n", p + 1, row, col, island_count);
            continue;
        }

        parent[idx] = idx;
        island_count++;

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];
            int nidx = nr * C + nc;

            if (nr >= 0 && nr < R && nc >= 0 && nc < C && parent[nidx] != -1) {
                if (unionSets(idx, nidx)) {
                    island_count--;
                }
            }
        }
        printf("  Step %d: Add Land at (%d, %d) -> Connected Islands: %d\n", p + 1, row, col, island_count);
    }
}

int main() {
    int r = 3, c = 3;
    int positions[][2] = {{0, 0}, {0, 1}, {1, 2}, {2, 1}, {1, 1}};
    int k = sizeof(positions) / sizeof(positions[0]);

    printf("--- QUESTION 2: DYNAMIC CONNECTED COMPONENTS IN A GRID ---\n");
    numIslands2(r, c, positions, k);
    return 0;
}