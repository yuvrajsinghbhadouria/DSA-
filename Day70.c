/*Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

Input:
- n vertices
- m edges (u,v,w)

Output:
- Shortest distances OR NEGATIVE CYCLE*/
#include <stdio.h>
#include <limits.h>

struct Edge {
    int u, v, w;
};

int main()
{
    int n, m, src;

    scanf("%d %d", &n, &m);

    struct Edge edges[m];

    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    scanf("%d", &src);

    int dist[n];

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    // Relax all edges n-1 times
    for (int i = 1; i <= n - 1; i++)
    {
        int updated = 0;

        for (int j = 0; j < m; j++)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX &&
                dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                updated = 1;
            }
        }

        if (!updated)
            break;
    }

    // One more relaxation to detect negative cycle
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (dist[u] != INT_MAX &&
            dist[u] + w < dist[v])
        {
            printf("NEGATIVE CYCLE\n");
            return 0;
        }
    }

    // Print shortest distances
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INT_MAX)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }

    printf("\n");

    return 0;
}
