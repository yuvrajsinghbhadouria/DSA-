/*Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED*/
#include <stdio.h>

void dfs(int node, int n, int adj[n][n], int visited[])
{
    visited[node] = 1;

    for (int i = 0; i < n; i++)
    {
        if (adj[node][i] == 1 && !visited[i])
            dfs(i, n, adj, visited);
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[n][n];
    int visited[n];

    // Initialize
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;

        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    // Read edges (1-based vertices)
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        u--;
        v--;

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // Start DFS from vertex 0
    dfs(0, n, adj, visited);

    // Check if every vertex was visited
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");

    return 0;
}

