#include <stdio.h>
#include <stdlib.h>

struct Node { int v; struct Node* next; };
struct Graph { int numV; struct Node** adj; int* vis; };

struct Graph* createGraph(int v) {
    struct Graph* g = malloc(sizeof(struct Graph));
    g->numV = v;
    g->adj = malloc(v * sizeof(struct Node*));
    g->vis = malloc(v * sizeof(int));
    for (int i = 0; i < v; i++) { g->adj[i] = NULL; g->vis[i] = 0; }
    return g;
}

void addEdge(struct Graph* g, int u, int v) {
    struct Node* n = malloc(sizeof(struct Node));
    n->v = v; n->next = g->adj[u]; g->adj[u] = n;
    n = malloc(sizeof(struct Node));
    n->v = u; n->next = g->adj[v]; g->adj[v] = n;
}
int isCyclicUtil(struct Graph* g, int v, int parent) {
    g->vis[v] = 1;
    struct Node* temp = g->adj[v];

    while (temp != NULL) {
        int adjV = temp->v;
        if (!g->vis[adjV]) {
            if (isCyclicUtil(g, adjV, v)) return 1;
        } 
        else if (adjV != parent) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void detectCycle(struct Graph* g) {
    for (int i = 0; i < g->numV; i++) {
        if (!g->vis[i]) {
            if (isCyclicUtil(g, i, -1)) {
                printf("YES\n");
                return;
            }
        }
    }
    printf("NO\n");
}

int main() {
    int n = 4;
    struct Graph* g = createGraph(n);
    addEdge(g, 0, 1);
    addEdge(g, 1, 2);
    addEdge(g, 2, 0);
    addEdge(g, 2, 3);

    detectCycle(g);
    return 0;
}
