#include <stdio.h>
#include <stdlib.h>

struct Node { int v; struct Node* next; };
struct Graph { int numV; struct Node** adj; int* vis; };
int stack[100];
int top = -1;

void push(int v) { stack[++top] = v; }

struct Graph* createGraph(int v) {
    struct Graph* g = malloc(sizeof(struct Graph));
    g->numV = v;
    g->adj = calloc(v, sizeof(struct Node*));
    g->vis = calloc(v, sizeof(int));
    return g;
}

void addEdge(struct Graph* g, int u, int v) {
    struct Node* n = malloc(sizeof(struct Node));
    n->v = v; n->next = g->adj[u]; g->adj[u] = n;
}
void topoSortUtil(struct Graph* g, int v) {
    g->vis[v] = 1;
    struct Node* temp = g->adj[v];

    while (temp) {
        if (!g->vis[temp->v]) {
            topoSortUtil(g, temp->v);
        }
        temp = temp->next;
    }
    push(v);
}

int main() {
    int n = 6;
    struct Graph* g = createGraph(n);

    // Example DAG edges
    addEdge(g, 5, 2); addEdge(g, 5, 0);
    addEdge(g, 4, 0); addEdge(g, 4, 1);
    addEdge(g, 2, 3); addEdge(g, 3, 1);

    for (int i = 0; i < n; i++) {
        if (!g->vis[i]) topoSortUtil(g, i);
    }

    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}
