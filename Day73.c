/*Problem Statement
Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.

Input Format
A single string s.

Output Format
Print the first non-repeating character or '$' if none exists.

Sample Input
geeksforgeeks

Sample Output
f

Explanation
The character 'f' occurs only once in the string and appears before any other non-repeating character.*/
#include <stdlib.h>

int find(int parent[], int x)
{
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);

    return parent[x];
}

int* findRedundantConnection(int** edges, int edgesSize,
                             int* edgesColSize, int* returnSize)
{
    int n = edgesSize;

    int *parent = malloc((n + 1) * sizeof(int));
    int *answer = malloc(2 * sizeof(int));

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    for (int i = 0; i < edgesSize; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        int pu = find(parent, u);
        int pv = find(parent, v);

        // Both vertices already belong to same set
        // -> this edge creates a cycle
        if (pu == pv)
        {
            answer[0] = u;
            answer[1] = v;

            *returnSize = 2;

            free(parent);
            return answer;
        }

        parent[pu] = pv;
    }

    *returnSize = 0;

    free(parent);
    free(answer);

    return NULL;
}
