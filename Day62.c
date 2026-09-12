/*Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- List of adjacency lists for each vertex*/
#include <stdio.h>
#include <stdlib.h>

// Node of linked list
struct Node
{
    int vertex;
    struct Node* next;
};

// Add an edge to adjacency list
void addEdge(struct Node* adj[], int u, int v)
{
    struct Node* newNode;

    // Add v to u's list
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    // Add u to v's list (undirected graph)
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

int main()
{
    int n, m;
    int u, v;
    int i;

    scanf("%d", &n);
    scanf("%d", &m);

    struct Node* adj[n];

    // Initialize all lists
    for (i = 0; i < n; i++)
        adj[i] = NULL;

    // Read edges
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    // Print adjacency lists
    for (i = 0; i < n; i++)
    {
        struct Node* temp = adj[i];

        printf("%d:", i);

        while (temp != NULL)
        {
            printf(" %d", temp->vertex);
            temp = temp->next;
        }

        printf("\n");
    }

    return 0;
}
