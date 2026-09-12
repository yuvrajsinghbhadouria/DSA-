/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int node;
    int dist;
} Pair;

typedef struct {
    Pair *data;
    int size;
    int capacity;
} MinHeap;

void swap(Pair *a, Pair *b)
{
    Pair temp = *a;
    *a = *b;
    *b = temp;
}

void push(MinHeap *heap, int node, int dist)
{
    if (heap->size == heap->capacity)
    {
        heap->capacity *= 2;
        heap->data = realloc(heap->data,
                             heap->capacity * sizeof(Pair));
    }

    int i = heap->size++;
    heap->data[i] = (Pair){node, dist};

    while (i > 0)
    {
        int parent = (i - 1) / 2;

        if (heap->data[parent].dist <= heap->data[i].dist)
            break;

        swap(&heap->data[parent], &heap->data[i]);
        i = parent;
    }
}

Pair pop(MinHeap *heap)
{
    Pair result = heap->data[0];
    heap->data[0] = heap->data[--heap->size];

    int i = 0;

    while (1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < heap->size &&
            heap->data[left].dist < heap->data[smallest].dist)
            smallest = left;

        if (right < heap->size &&
            heap->data[right].dist < heap->data[smallest].dist)
            smallest = right;

        if (smallest == i)
            break;

        swap(&heap->data[i], &heap->data[smallest]);
        i = smallest;
    }

    return result;
}

int* dijkstra(int V, int** edges, int E, int src)
{
    int **adj = malloc(V * sizeof(int *));
    int *degree = calloc(V, sizeof(int));

    for (int i = 0; i < E; i++)
    {
        degree[edges[i][0]]++;
        degree[edges[i][1]]++;
    }

    for (int i = 0; i < V; i++)
        adj[i] = malloc(2 * degree[i] * sizeof(int));

    int index[V];

    for (int i = 0; i < V; i++)
        index[i] = 0;

    for (int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u][index[u]++] = v;
        adj[u][index[u]++] = w;

        adj[v][index[v]++] = u;
        adj[v][index[v]++] = w;
    }

    int *dist = malloc(V * sizeof(int));

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    MinHeap heap;
    heap.size = 0;
    heap.capacity = 16;
    heap.data = malloc(heap.capacity * sizeof(Pair));

    push(&heap, src, 0);

    while (heap.size > 0)
    {
        Pair current = pop(&heap);

        int u = current.node;
        int d = current.dist;

        if (d != dist[u])
            continue;

        for (int i = 0; i < 2 * degree[u]; i += 2)
        {
            int v = adj[u][i];
            int w = adj[u][i + 1];

            if (dist[u] != INT_MAX &&
                dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                push(&heap, v, dist[v]);
            }
        }
    }

    for (int i = 0; i < V; i++)
        free(adj[i]);

    free(adj);
    free(degree);
    free(heap.data);

    return dist;
}