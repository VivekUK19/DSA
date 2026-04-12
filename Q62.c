#include <stdio.h>
#include <stdlib.h>
struct Node {
    int vertex;
    struct Node* next;
};
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    struct Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        struct Node* temp = adj[i];
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
    return 0;
}
