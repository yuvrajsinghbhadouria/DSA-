/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int node;
    int dist;
} Pair;

void swap(Pair *a, Pair *b)
{
    Pair temp = *a;
    *a = *b;
    *b = temp;
}

void push(Pair heap[], int *size, Pair x)
{
    int i = (*size)++;
    heap[i] = x;

    while (i > 0)
    {
        int parent = (i - 1) / 2;

        if (heap[parent].dist <= heap[i].dist)
            break;

        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}

Pair pop(Pair heap[], int *size)
{
    Pair result = heap[0];
    heap[0] = heap[--(*size)];

    int i = 0;

    while (1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < *size &&
            heap[left].dist < heap[smallest].dist)
            smallest = left;

        if (right < *size &&
            heap[right].dist < heap[smallest].dist)
            smallest = right;

        if (smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }

    return result;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        u--;
        v--;

        graph[u][v] = w;
        graph[v][u] = w;
    }

    int source;
    scanf("%d", &source);
    source--;

    int dist[n];

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[source] = 0;

    Pair heap[10000];
    int size = 0;

    push(heap, &size, (Pair){source, 0});

    while (size > 0)
    {
        Pair current = pop(heap, &size);

        int u = current.node;
        int d = current.dist;

        if (d != dist[u])
            continue;

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] != 0)
            {
                int newDist = dist[u] + graph[u][v];

                if (newDist < dist[v])
                {
                    dist[v] = newDist;
                    push(heap, &size, (Pair){v, newDist});
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d ", dist[i]);

    printf("\n");

    return 0;
}
