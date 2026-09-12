/*Problem Statement:
Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO

Example:
Input:
7
1 3 5 7 9 8 10

Output:
YES

Explanation:
Each parent node must be smaller than its children.*/
```c
#include <stdio.h>

int isMinHeap(int a[], int n)
{
    int i;
    int left, right;

    for (i = 0; i < n; i++)
    {
        left = 2 * i + 1;
        right = 2 * i + 2;

        // Check left child
        if (left < n && a[i] > a[left])
            return 0;

        // Check right child
        if (right < n && a[i] > a[right])
            return 0;
    }

    return 1;
}

int main()
{
    int n;
    int a[1000];
    int i;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    if (isMinHeap(a, n))
        printf("YES");
    else
        printf("NO");

    return 0;
}
```
