/*Problem Statement
Using DFS or BFS, count number of connected components.

Input Format
n m
edges

Output Format
Number of connected components.

Sample Input
6 3
1 2
2 3
5 6

Sample Output
3

Explanation
Components: {1,2,3}, {4}, {5,6}*/
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

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;

        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        // For 1-based input
        u--;
        v--;

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int components = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            components++;
            dfs(i, n, adj, visited);
        }
    }

    printf("%d\n", components);

    return 0;
}
