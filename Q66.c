#include <stdio.h>
#include <stdlib.h>

struct Node { int v; struct Node* next; };
struct Graph { 
    int numV; 
    struct Node** adj; 
    int* vis; 
    int* recStack;
};

struct Graph* createGraph(int v) {
    struct Graph* g = malloc(sizeof(struct Graph));
    g->numV = v;
    g->adj = calloc(v, sizeof(struct Node*));
    g->vis = calloc(v, sizeof(int));
    g->recStack = calloc(v, sizeof(int));
    return g;
}

void addDirectedEdge(struct Graph* g, int u, int v) {
    struct Node* n = malloc(sizeof(struct Node));
    n->v = v; n->next = g->adj[u]; g->adj[u] = n;
}

int isCyclicUtil(struct Graph* g, int v) {
    if (!g->vis[v]) {
        g->vis[v] = 1;
        g->recStack[v] = 1;

        struct Node* temp = g->adj[v];
        while (temp) {
            int adjV = temp->v;
            // If not visited, recurse. If already in stack, cycle!
            if (!g->vis[adjV] && isCyclicUtil(g, adjV)) return 1;
            else if (g->recStack[adjV]) return 1;
            
            temp = temp->next;
        }
    }
    g->recStack[v] = 0;
    return 0;
}

int main() {
    int n = 4;
    struct Graph* g = createGraph(n);
    addDirectedEdge(g, 0, 1);
    addDirectedEdge(g, 1, 2);
    addDirectedEdge(g, 2, 0);
    addDirectedEdge(g, 2, 3);

    for (int i = 0; i < n; i++) {
        if (isCyclicUtil(g, i)) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
