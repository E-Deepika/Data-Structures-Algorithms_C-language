#include <stdio.h>

int main() {
    int n, e;

    scanf("%d %d", &n, &e);

    // Adjacency matrix
    int adj[n + 1][n + 1];

    // Initialize matrix with 0
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    // Input edges
    for (int i = 0; i < e; i++) {
        int f, t;

        scanf("%d %d", &f, &t);

        adj[f][t] = 1;
        adj[t][f] = 1;
    }

    // Print adjacency matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}

//Time Complexity: O(E)
//Space complexity: O(n*n)

