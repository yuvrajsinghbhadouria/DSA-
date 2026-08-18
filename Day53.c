/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct {
    Node *node;
    int hd;
} QueueItem;

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

void verticalOrder(Node* root, int n) {
    if (root == NULL)
        return;

    QueueItem* queue = (QueueItem*)malloc(n * sizeof(QueueItem));

    int front = 0;
    int rear = 0;

    queue[rear].node = root;
    queue[rear].hd = 0;
    rear++;

    // Maximum possible horizontal distance is -(n-1) to +(n-1)
    int offset = n;
    int size = 2 * n + 1;

    int** columns = (int**)malloc(size * sizeof(int*));
    int* count = (int*)calloc(size, sizeof(int));

    for (int i = 0; i < size; i++)
        columns[i] = (int*)malloc(n * sizeof(int));

    int minHD = 0;
    int maxHD = 0;

    // BFS ensures top-to-bottom and left-to-right order
    while (front < rear) {
        QueueItem current = queue[front++];

        int hd = current.hd;
        int index = hd + offset;

        columns[index][count[index]++] = current.node->data;

        if (hd < minHD)
            minHD = hd;

        if (hd > maxHD)
            maxHD = hd;

        if (current.node->left != NULL) {
            queue[rear].node = current.node->left;
            queue[rear].hd = hd - 1;
            rear++;
        }

        if (current.node->right != NULL) {
            queue[rear].node = current.node->right;
            queue[rear].hd = hd + 1;
            rear++;
        }
    }

    // Print from leftmost vertical line to rightmost
    for (int hd = minHD; hd <= maxHD; hd++) {
        int index = hd + offset;

        for (int j = 0; j < count[index]; j++) {
            printf("%d", columns[index][j]);

            if (j < count[index] - 1)
                printf(" ");
        }

        printf("\n");
    }

    for (int i = 0; i < size; i++)
        free(columns[i]);

    free(columns);
    free(count);
    free(queue);
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];

    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, N);

    verticalOrder(root, N);

    return 0;
}