#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
    int u, v;
    struct Edge* next;
} Edge;

Edge* adj[1005];
int weights[1005];
int parent[1005];
long long comp_sum[1005];
int active[1005];

void addEdge(int u, int v) {
    Edge* e1 = (Edge*)malloc(sizeof(Edge));
    e1->u = u; e1->v = v; e1->next = adj[u]; adj[u] = e1;
    Edge* e2 = (Edge*)malloc(sizeof(Edge));
    e2->u = v; e2->v = u; e2->next = adj[v]; adj[v] = e2;
}

int find(int i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

void reverseTimeDSU(int V, int P[]) {
    for (int i = 1; i <= V; i++) {
        parent[i] = i;
        comp_sum[i] = weights[i];
        active[i] = 0;
    }

    long long max_sums[V + 1];
    long long current_max = 0;
    max_sums[V] = 0; // After all vertices deleted

    // Process deletion sequence in reverse (from V-1 down to 0)
    for (int step = V - 1; step >= 1; step--) {
        int u = P[step];
        active[u] = 1;
        if (comp_sum[u] > current_max) current_max = comp_sum[u];

        for (Edge* e = adj[u]; e != NULL; e = e->next) {
            int v = e->v;
            if (active[v]) {
                int r_u = find(u);
                int r_v = find(v);
                if (r_u != r_v) {
                    parent[r_u] = r_v;
                    comp_sum[r_v] += comp_sum[r_u];
                    if (comp_sum[r_v] > current_max) current_max = comp_sum[r_v];
                }
            }
        }
        max_sums[step] = current_max;
    }

    printf("Max Component Weight Sum after each vertex deletion:\n");
    for (int i = 0; i < V; i++) {
        printf("  After Deleting Vertex P[%d] = %d: Max Sum = %lld\n", i + 1, P[i], max_sums[i + 1]);
    }
}

int main() {
    int V = 4;
    weights[1] = 10; weights[2] = 20; weights[3] = 30; weights[4] = 40;

    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 4);

    int P[] = {1, 3, 2, 4}; // Deletion order

    printf("--- QUESTION 4: REVERSE TIME-STEP DSU APPLICATION ---\n");
    reverseTimeDSU(V, P);
    return 0;
}