#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int parent;
    int parity; // Parity of path distance to root (0 or 1)
} DSU;

DSU dsu[1005];

void initDSU(int n) {
    for (int i = 1; i <= n; i++) {
        dsu[i].parent = i;
        dsu[i].parity = 0;
    }
}

// Find with path compression and parity tracking
int findDSU(int i) {
    if (dsu[i].parent == i) return i;
    int orig_parent = dsu[i].parent;
    int root = findDSU(dsu[i].parent);
    dsu[i].parent = root;
    dsu[i].parity ^= dsu[orig_parent].parity;
    return root;
}

int addEdge(int u, int v) {
    int root_u = findDSU(u);
    int root_v = findDSU(v);

    if (root_u == root_v) {
        // If same root and same parity, adding edge creates an odd-length cycle
        if (dsu[u].parity == dsu[v].parity) {
            return 0; // Violates bipartiteness
        }
        return 1; // Already in same component without odd cycle
    }

    // Union components and update root parity
    dsu[root_u].parent = root_v;
    dsu[root_u].parity = dsu[u].parity ^ dsu[v].parity ^ 1;
    return 1;
}

int main() {
    int V = 4;
    initDSU(V);

    int edges[][2] = {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 3}};
    int num_edges = sizeof(edges) / sizeof(edges[0]);

    printf("--- QUESTION 1: ONLINE GRAPH-BIPARTITENESS TESTING ---\n");
    for (int i = 0; i < num_edges; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        if (addEdge(u, v)) {
            printf("Edge (%d, %d): Added successfully (Graph remains Bipartite)\n", u, v);
        } else {
            printf("Edge (%d, %d): REJECTED! Violates Bipartiteness (Creates Odd Cycle)\n", u, v);
        }
    }
    return 0;
}