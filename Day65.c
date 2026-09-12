/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO*/
#include <stdio.h>
#include <stdbool.h>

bool dfs(int node, int parent, int V, int adj[V][V], bool visited[])
{
    visited[node] = true;

    for (int i = 0; i < V; i++)
    {
        if (adj[node][i])
        {
            if (!visited[i])
            {
                if (dfs(i, node, V, adj, visited))
                    return true;
            }
            else if (i != parent)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int V, E;
    scanf("%d %d", &V, &E);

    int adj[V][V];
    bool visited[V];

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
        adj[v][u] = 1;
    }

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1, V, adj, visited))
            {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");

    return 0;
}

