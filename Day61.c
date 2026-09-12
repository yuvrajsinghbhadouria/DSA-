/*Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.

Input:
- n (vertices)
- m (edges)
- m pairs (u, v)

Output:
- n x n adjacency matrix*/
#include <stdio.h>

int main()
{
    int n, m;
    int adj[100][100] = {0};
    int u, v;
    int i, j;

    // Number of vertices
    scanf("%d", &n);

    // Number of edges
    scanf("%d", &m);

    // Read edges
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);

        // Undirected graph
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // Print adjacency matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}

