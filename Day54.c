/*Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order

Example:
Input:
7
1 2 3 4 5 6 7

Output:
1 3 2 4 5 6 7

Explanation:
Level 1 is printed left-to-right, level 2 right-to-left, and so on.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    Node* root = createNode(arr[0]);

    Node** queue = (Node**)malloc(n * sizeof(Node*));
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    while (front < rear && i < n) {
        Node* current = queue[front++];

        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    free(queue);
    return root;
}

void zigzagTraversal(Node* root, int n) {
    if (root == NULL)
        return;

    Node** queue = (Node**)malloc(n * sizeof(Node*));

    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    int leftToRight = 1;

    while (front < rear) {
        int levelSize = rear - front;

        int* level = (int*)malloc(levelSize * sizeof(int));

        for (int i = 0; i < levelSize; i++) {
            Node* current = queue[front++];

            level[i] = current->data;

            if (current->left != NULL)
                queue[rear++] = current->left;

            if (current->right != NULL)
                queue[rear++] = current->right;
        }

        if (leftToRight) {
            for (int i = 0; i < levelSize; i++)
                printf("%d ", level[i]);
        } else {
            for (int i = levelSize - 1; i >= 0; i--)
                printf("%d ", level[i]);
        }

        free(level);

        leftToRight = !leftToRight;
    }

    free(queue);
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];

    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, N);

    zigzagTraversal(root, N);

    return 0;
}