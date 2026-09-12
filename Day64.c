/*Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order*/
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

    // u -> v
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    // v -> u (undirected)
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

// BFS
void bfs(int source, struct Node* adj[], int n)
{
    int visited[n];
    int queue[n];
    int front = 0;
    int rear = 0;

    int i;

    // Initialize visited array
    for (i = 0; i < n; i++)
        visited[i] = 0;

    // Start with source
    visited[source] = 1;
    queue[rear++] = source;

    while (front < rear)
    {
        int current = queue[front++];

        printf("%d ", current);

        struct Node* temp = adj[current];

        while (temp != NULL)
        {
            int next = temp->vertex;

            if (visited[next] == 0)
            {
                visited[next] = 1;
                queue[rear++] = next;
            }

            temp = temp->next;
        }
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

    // Initialize adjacency list
    for (i = 0; i < n; i++)
        adj[i] = NULL;

    // Read edges
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    // Source vertex
    scanf("%d", &s);

    // Perform BFS
    bfs(s, adj, n);

    return 0;
}

