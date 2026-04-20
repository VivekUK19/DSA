#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

struct Node {
    int dest;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];
int visited_count = 0;

void dfs(int v) {
    visited[v] = 1;
    visited_count++;
    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->dest]) {
            dfs(temp->dest);
        }
        temp = temp->next;
    }
}

void addEdge(int u, int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->dest = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = malloc(sizeof(struct Node));
    newNode->dest = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    if (n == 0) return 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    dfs(1);
    if (visited_count == n) {
        printf("CONNECTED\n");
    } else {
        printf("NOT CONNECTED\n");
    }
    return 0;
}

