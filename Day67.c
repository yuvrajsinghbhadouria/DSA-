/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/
#include <stdio.h>
#include <stdbool.h>

void dfs(int node, int V, int adj[V][V], bool visited[], int stack[], int *top)
{
    visited[node] = true;

    for (int i = 0; i < V; i++)
    {
        if (adj[node][i] && !visited[i])
        {
            dfs(i, V, adj, visited, stack, top);
        }
    }

    stack[(*top)++] = node;
}

int main()
{
    int V, E;
    scanf("%d %d", &V, &E);

    int adj[V][V];
    bool visited[V];
    int stack[V];
    int top = 0;

    for (int i = 0; i < V; i++)
    {
        visited[i] = false;

        for (int j = 0; j < V; j++)
            adj[i][j] = 0;
    }

    for (int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
    }

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            dfs(i, V, adj, visited, stack, &top);
    }

    for (int i = top - 1; i >= 0; i--)
        printf("%d ", stack[i]);

    printf("\n");

    return 0;
}