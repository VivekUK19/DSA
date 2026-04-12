#include <stdio.h>
#include <stdlib.h>

#define MAX 100
struct Node { int vertex; struct Node* next; };
struct Graph { int numV; struct Node** adj; int* vis; };
struct Queue { int items[MAX]; int f, r; };
struct Node* newNode(int v) {
    struct Node* n = malloc(sizeof(struct Node));
    n->vertex = v; n->next = NULL;
    return n;
}
struct Graph* createGraph(int v) {
    struct Graph* g = malloc(sizeof(struct Graph));
    g->numV = v;
    g->adj = malloc(v * sizeof(struct Node*));
    g->vis = malloc(v * sizeof(int));
    for (int i = 0; i < v; i++) { g->adj[i] = NULL; g->vis[i] = 0; }
    return g;
}
void addEdge(struct Graph* g, int u, int v) {
    struct Node* n = newNode(v);
    n->next = g->adj[u]; g->adj[u] = n;
    n = newNode(u);
    n->next = g->adj[v]; g->adj[v] = n;
}
struct Queue* createQ() {
    struct Queue* q = malloc(sizeof(struct Queue));
    q->f = -1; q->r = -1;
    return q;
}
void enqueue(struct Queue* q, int v) {
    if (q->r == MAX - 1) return;
    if (q->f == -1) q->f = 0;
    q->items[++q->r] = v;
}
int dequeue(struct Queue* q) {
    if (q->f == -1) return -1;
    int i = q->items[q->f++];
    if (q->f > q->r) q->f = q->r = -1;
    return i;
}
void bfs(struct Graph* g, int start) {
    struct Queue* q = createQ();
    g->vis[start] = 1; enqueue(q, start);
    while (q->f != -1) {
        int c = dequeue(q);
        printf("%d ", c);
        struct Node* temp = g->adj[c];
        while (temp) {
            if (g->vis[temp->vertex] == 0) {
                g->vis[temp->vertex] = 1;
                enqueue(q, temp->vertex);
            }
            temp = temp->next;
        }
    }
}
int main() {
    struct Graph* g = createGraph(4);
    addEdge(g, 0, 1); addEdge(g, 0, 2);
    addEdge(g, 1, 3); addEdge(g, 2, 3);
    printf("BFS traversal (start 0):\n");
    bfs(g, 0);
    return 0;
}
