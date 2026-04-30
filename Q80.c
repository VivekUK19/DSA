#include <stdio.h>

#define INF 1e9 // Large value to represent infinity

void floydWarshall(int n, int matrix[n][n]) {
    int dist[n][n];

    // Initialize the distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) dist[i][j] = 0;
            else if (matrix[i][j] == -1) dist[i][j] = INF;
            else dist[i][j] = matrix[i][j];
        }
    }

    // Core Algorithm: Try every vertex as an intermediate point
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && 
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print result
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) printf("-1 ");
            else printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int matrix[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    floydWarshall(n, matrix);
    return 0;
}
