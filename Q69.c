#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

struct Node { int v, w; struct Node* next; };
struct Graph { int numV; struct Node** adj; };
struct HeapNode { int v, dist; };
struct PriorityQueue { struct HeapNode* heap; int size; };

// Min-Heap Helper: Bubbles up the last element to maintain heap property
void push(struct PriorityQueue* pq, int v, int dist) {
    int i = pq->size++;
    pq->heap[i].v = v; pq->heap[i].dist = dist;
    while (i != 0 && pq->heap[(i - 1) / 2].dist > pq->heap[i].dist) {
        struct HeapNode temp = pq->heap[i];
        pq->heap[i] = pq->heap[(i - 1) / 2];
        pq->heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Extracts the vertex with the minimum distance
struct HeapNode pop(struct PriorityQueue* pq) {
    struct HeapNode root = pq->heap[0];
    pq->heap[0] = pq->heap[--pq->size];
    int i = 0;
    while (2 * i + 1 < pq->size) {
        int left = 2 * i + 1, right = 2 * i + 2, smallest = left;
        if (right < pq->size && pq->heap[right].dist < pq->heap[left].dist) smallest = right;
        if (pq->heap[i].dist <= pq->heap[smallest].dist) break;
        struct HeapNode temp = pq->heap[i];
        pq->heap[i] = pq->heap[smallest];
        pq->heap[smallest] = temp;
        i = smallest;
    }
    return root;
}

void dijkstra(struct Graph* g, int src) {
    int* dist = malloc(g->numV * sizeof(int));
    for (int i = 0; i < g->numV; i++) dist[i] = INF;

    struct PriorityQueue pq;
    pq.heap = malloc(g->numV * g->numV * sizeof(struct HeapNode));
    pq.size = 0;

    dist[src] = 0;
    push(&pq, src, 0);

    while (pq.size != 0) {
        struct HeapNode minNode = pop(&pq);
        int u = minNode.v;

        if (minNode.dist > dist[u]) continue; // Skip if a better path was already found

        struct Node* temp = g->adj[u];
        while (temp) {
            if (dist[u] != INF && dist[u] + temp->w < dist[temp->v]) {
                dist[temp->v] = dist[u] + temp->w;
                push(&pq, temp->v, dist[temp->v]);
            }
            temp = temp->next;
        }
    }

    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < g->numV; i++) printf("To %d: %d\n", i, dist[i]);
}

