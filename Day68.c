/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1000

int main()
{
    int V, E;
    scanf("%d %d", &V, &E);

    int adj[MAX_VERTICES][MAX_VERTICES];
    int indegree[MAX_VERTICES] = {0};

    // Initialize adjacency matrix
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            adj[i][j] = 0;
        }
    }

    // Read edges and update in-degrees
    for (int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    // Find nodes with in-degree 0
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            queue[rear++] = i;
        }
    }

    // Kahn's Algorithm
    while (front < rear)
    {
        int node = queue[front++];
        printf("%d ", node);

        for (int j = 0; j < V; j++)
        {
            if (adj[node][j])
            {
                indegree[j]--;
                if (indegree[j] == 0)
                {
                    queue[rear++] = j;
                }
            }
        }
    }

    printf("\n");

    return 0;
}
