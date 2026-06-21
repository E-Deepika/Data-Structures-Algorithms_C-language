#include <stdio.h>

#define MAX 100

// Queue
int queue[MAX];
int front = -1, rear = -1;


// ENQUEUE

void enqueue(int val)
{
    if (rear == MAX - 1)
        return;

    if (front == -1)
        front = 0;

    queue[++rear] = val;
}


// DEQUEUE

int dequeue()
{
    int val = queue[front];

    if (front == rear)
        front = rear = -1;
    else
        front++;

    return val;
}

 
// CHECK EMPTY
 
int isEmpty()
{
    return (front == -1);
}

 
// BFS 

void bfs(int n, int adj[][100], int size[])
{
    int visited[100] = {0};

    // Start from vertex 0
    visited[0] = 1;

    enqueue(0);

    printf("BFS Traversal: ");

    while (!isEmpty())
    {
        int current = dequeue();

        printf("%d ", current);

        // Visit neighbours
        for (int i = 0; i < size[current]; i++)
        {
            int next = adj[current][i];

            if (!visited[next])
            {
                visited[next] = 1;
                enqueue(next);
            }
        }
    }
}



int main()
{
    int n, e;

    // Number of vertices and edges
    scanf("%d %d", &n, &e);

    int adj[100][100];
    int size[100] = {0};

    // Input graph
    for (int i = 0; i < e; i++)
    {
        int f, t;

        scanf("%d %d", &f, &t);

        adj[f][size[f]] = t;
        size[f]++;

        adj[t][size[t]] = f;
        size[t]++;
    }

    // Run BFS
    bfs(n, adj, size);

    return 0;
}
