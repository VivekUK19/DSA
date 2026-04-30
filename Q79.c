#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int to, weight;
} Edge;

typedef struct {
    int dist, u;
} Node;

// Basic Min-Heap implementation for Priority Queue
typedef struct {
    Node *data;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap(int capacity) {
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h->data = (Node*)malloc(sizeof(Node) * capacity);
    h->size = 0;
    h->capacity = capacity;
    return h;
}

void push(MinHeap* h, int dist, int u) {
    int i = h->size++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->data[p].dist <= dist) break;
        h->data[i] = h->data[p];
        i = p;
    }
    h->data[i].dist = dist;
    h->data[i].u = u;
}

Node pop(MinHeap* h) {
    Node res = h->data[0];
    Node last = h->data[--h->size];
    int i = 0;
    while (i * 2 + 1 < h->size) {
        int child = i * 2 + 1;
        if (child + 1 < h->size && h->data[child+1].dist < h->data[child].dist) child++;
        if (last.dist <= h->data[child].dist) break;
        h->data[i] = h->data[child];
        i = child;
    }
    h->data[i] = last;
    return res;
}

void dijkstra(int n, int m, int edges[][3], int source) {
    int dist[n + 1];
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
    dist[source] = 0;

    MinHeap* pq = createHeap(m * 2);
    push(pq, 0, source);

    while (pq->size > 0) {
        Node top = pop(pq);
        int d = top.dist;
        int u = top.u;

        if (d > dist[u]) continue;

        for (int i = 0; i < m; i++) {
            int v = -1, w = edges[i][2];
            if (edges[i][0] == u) v = edges[i][1];
            else if (edges[i][1] == u) v = edges[i][0];

            if (v != -1 && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(pq, dist[v], v);
            }
        }
    }

    for (int i = 1; i <= n; i++) printf("%d ", dist[i]);
    printf("\n");
}

int main() {
    int n = 5, m = 6;
    int edges[6][3] = {{1, 2, 2}, {1, 3, 4}, {2, 3, 1}, {2, 4, 7}, {3, 5, 3}, {4, 5, 1}};
    int source = 1;
    dijkstra(n, m, edges, source);
    return 0;
}
