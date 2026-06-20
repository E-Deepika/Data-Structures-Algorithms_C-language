#include <stdio.h>

// Stores graph
int adj[100][100];

// Stores number of neighbours for each node
int size[100];

// Marks visited nodes
int visited[100] = {0};

// Stores DFS output
int ans[100];

// Position in answer array
int index = 0;


// Recursive DFS function
void dfs(int cur)
{
    // Store current node in answer
    ans[index] = cur;

    // Move to next position
    index++;

    // Mark current node visited
    visited[cur] = 1;

    // Visit all neighbours
    for(int i = 0; i < size[cur]; i++)
    {
        int k = adj[cur][i];

        // Visit only unvisited nodes
        if(visited[k] == 0)
        {
            dfs(k);
        }
    }
}


int main()
{
    int n, e;

    // Read number of nodes and edges
    scanf("%d %d", &n, &e);

    // Read graph
    for(int i = 0; i < e; i++)
    {
        int f, t;

        scanf("%d %d", &f, &t);

        // Add edge f -> t
        adj[f][size[f]] = t;
        size[f]++;

        // Add edge t -> f
        adj[t][size[t]] = f;
        size[t]++;
    }

    // Start DFS from node 0
    dfs(0);

    // Print DFS result
    for(int i = 0; i < index; i++)
    {
        printf("%d ", ans[i]);
    }

    return 0;
}
