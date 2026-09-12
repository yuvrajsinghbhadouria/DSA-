/*Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)*/
#include <stdio.h>

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

    int visited[n];
    int key[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        key[i] = 1000000000;
    }

    key[0] = 0;

    int total = 0;

    for (int count = 0; count < n; count++)
    {
        int u = -1;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] &&
                (u == -1 || key[i] < key[u]))
            {
                u = i;
            }
        }

        visited[u] = 1;
        total += key[u];

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", total);

    return 0;
}
