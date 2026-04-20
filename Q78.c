#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 1005
#define INF INT_MAX

int graph[MAX][MAX];
int key[MAX];  
bool inMST[MAX]; 

int minKey(int n) {
    int min = INF, min_index;
    for (int v = 1; v <= n; v++) {
        if (!inMST[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST(int n) {
    for (int i = 1; i <= n; i++) {
        key[i] = INF;
        inMST[i] = false;
    }

    key[1] = 0;
    int total_weight = 0;

    for (int count = 0; count < n; count++) {
        int u = minKey(n);
        inMST[u] = true;
        total_weight += key[u];

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }
    printf("%d\n", total_weight);
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        if (graph[u][v] == 0 || w < graph[u][v]) {
            graph[u][v] = w;
            graph[v][u] = w;
        }
    }
    primMST(n);
    return 0;
}
