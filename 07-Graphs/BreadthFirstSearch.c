#include <stdio.h>

void bfs(int n, int adj[][100], int size[]) {

    int queue[100];
    int front = 0;
    int rear = 0;

    int visited[100] = {0};

    // Start from node 0
    queue[rear++] = 0;
    visited[0] = 1;

    while (front < rear) {

        int cur = queue[front++];
        printf("%d ", cur);

        for (int i = 0; i < size[cur]; i++) {

            int k = adj[cur][i];

            if (!visited[k]) {

                queue[rear++] = k;
                visited[k] = 1;
            }
        }
    }
}

int main() {

    int n, e;

    scanf("%d %d", &n, &e);

    int adj[100][100];
    int size[100] = {0};

    // Input graph
    for (int i = 0; i < e; i++) {

        int f, t;

        scanf("%d %d", &f, &t);

        adj[f][size[f]] = t;
        size[f]++;

        adj[t][size[t]] = f;
        size[t]++;
    }

    bfs(n, adj, size);

    return 0;
}
