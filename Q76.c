#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

struct Node {
    int dest;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];
void dfs(int v) {
    visited[v] = 1;
    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->dest]) {
            dfs(temp->dest);
        }
        temp = temp->next;
    }
}
void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components++;
            dfs(i);
        }
    }

    printf("%d\n", components);
    return 0;
}
