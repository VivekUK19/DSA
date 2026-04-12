#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 1e9 // Use a large value to avoid overflow compared to INT_MAX

struct Edge { int u, v, w; };

void bellmanFord(int n, int m, struct Edge edges[], int src) {
    int* dist = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[src] = 0;

    // 1. Relax all edges (n - 1) times
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // 2. Check for negative weight cycles
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            free(dist);
            return;
        }
    }

    // 3. Print result
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");
    free(dist);
}

int main() {
    int n = 4, m = 4;
    struct Edge edges[] = {
        {0, 1, 1}, {1, 2, -1}, {2, 3, -1}, {3, 0, -1} // Contains a negative cycle
    };

    bellmanFord(n, m, edges, 0);
    return 0;
}
