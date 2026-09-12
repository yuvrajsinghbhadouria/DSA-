/*Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int vertex;
    struct Node* next;
};

// Add edge
void addEdge(struct Node* adj[], int u, int v)
{
    struct Node* newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    // For undirected graph
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

// DFS
void dfs(int vertex, struct Node* adj[], int visited[])
{
    struct Node* temp;

    visited[vertex] = 1;
    printf("%d ", vertex);

    temp = adj[vertex];

    while (temp != NULL)
    {
        if (visited[temp->vertex] == 0)
        {
            dfs(temp->vertex, adj, visited);
        }

        temp = temp->next;
    }
}

int main()
{
    int n, m;
    int u, v, s;
    int i;

    scanf("%d", &n);
    scanf("%d", &m);

    struct Node* adj[n];
    int visited[n];

    // Initialize
    for (i = 0; i < n; i++)
    {
        adj[i] = NULL;
        visited[i] = 0;
    }

    // Input edges
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    // Starting vertex
    scanf("%d", &s);

    // DFS traversal
    dfs(s, adj, visited);

    return 0;
}
