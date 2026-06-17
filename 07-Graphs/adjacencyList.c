#include <stdio.h>

int main() {
    int n, e;

    scanf("%d %d", &n, &e);

    // Stores adjacent vertices
    int adj[n + 1][n + 1];

    // Stores count of neighbors for each node
    int size[n + 1];

    // Initialize size array
    for (int i = 0; i <= n; i++) {
        size[i] = 0;
    }

    // Input edges
    for (int i = 0; i < e; i++) {
        int f, t;

        scanf("%d %d", &f, &t);

        // Add t to f's list
        adj[f][size[f]] = t;
        size[f]++;

        // Add f to t's list
        adj[t][size[t]] = f;
        size[t]++;
    }

    // Print adjacency list
    for (int i = 1; i <= n; i++) {
        printf("%d -> ", i);

        for (int j = 0; j < size[i]; j++) {
            printf("%d ", adj[i][j]);
        }

        printf("\n");
    }

    return 0;
}