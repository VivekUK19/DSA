#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node { int v; struct Node* next; };
struct Graph { int numV; struct Node** adj; int* inDegree; };

struct Graph* createGraph(int v) {
    struct Graph* g = malloc(sizeof(struct Graph));
    g->numV = v;
    g->adj = calloc(v, sizeof(struct Node*));
    g->inDegree = calloc(v, sizeof(int));
    return g;
}

void addEdge(struct Graph* g, int u, int v) {
    struct Node* n = malloc(sizeof(struct Node));
    n->v = v; n->next = g->adj[u]; g->adj[u] = n;
    g->inDegree[v]++;
}

void kahnSort(struct Graph* g) {
    int queue[MAX], front = 0, rear = 0;
    int topoOrder[MAX], count = 0;
    for (int i = 0; i < g->numV; i++) {
        if (g->inDegree[i] == 0) queue[rear++] = i;
    }
    while (front < rear) {
        int u = queue[front++];
        topoOrder[count++] = u;

        struct Node* temp = g->adj[u];
        while (temp) {
            int v = temp->v;
            g->inDegree[v]--; // "Remove" edge (u, v)
            if (g->inDegree[v] == 0) queue[rear++] = v;
            temp = temp->next;
        }
    }
    if (count != g->numV) {
        printf("Graph contains a cycle!\n");
    } else {
        printf("Topological Order: ");
        for (int i = 0; i < count; i++) printf("%d ", topoOrder[i]);
        printf("\n");
    }
}
int main() {
    struct Graph* g = createGraph(6);
    addEdge(g, 5, 2); addEdge(g, 5, 0);
    addEdge(g, 4, 0); addEdge(g, 4, 1);
    addEdge(g, 2, 3); addEdge(g, 3, 1);
    kahnSort(g);
    return 0;
}
