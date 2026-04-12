#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node { int vertex; struct Node* next; };
struct Graph { int numV; struct Node** adj; int* visited; };
struct Queue { int items[MAX]; int f, r; };
void enqueue(struct Queue* q, int v) {
    if (q->f == -1) q->f = 0;
    q->items[++q->r] = v;
}
int dequeue(struct Queue* q) {
    int item = q->items[q->f++];
    if (q->f > q->r) q->f = q->r = -1;
    return item;
}

void bfs(struct Graph* g, int s) {
    struct Queue q = {.f = -1, .r = -1};
    
    g->visited[s] = 1;
    enqueue(&q, s);

    while (q.f != -1) {
        int curr = dequeue(&q);
        printf("%d ", curr);

        struct Node* temp = g->adj[curr];
        while (temp) {
            int adjV = temp->vertex;
            if (!g->visited[adjV]) {
                g->visited[adjV] = 1;
                enqueue(&q, adjV);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n = 4, s = 0;
    struct Graph* g = malloc(sizeof(struct Graph));
    g->numV = n;
    g->adj = calloc(n, sizeof(struct Node*));
    g->visited = calloc(n, sizeof(int));
    printf("BFS Order: ");
    bfs(g, s);
    return 0;
}
