/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/
#include <stdio.h>
#include <stdbool.h>

bool dfs(int node, int V, int adj[V][V], bool visited[], bool recStack[])
{
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < V; i++)
    {
        if (adj[node][i])
        {
            if (!visited[i])
            {
                if (dfs(i, V, adj, visited, recStack))
                    return true;
            }
            else if (recStack[i])
            {
                return true;
            }
        }
    }

    recStack[node] = false;
    return false;
}

int main()
{
    int V, E;
    scanf("%d %d", &V, &E);

    int adj[V][V];
    bool visited[V];
    bool recStack[V];

    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;

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
        {
            if (dfs(i, V, adj, visited, recStack))
            {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");

    return 0;
}
