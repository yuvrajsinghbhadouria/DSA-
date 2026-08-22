/*Problem Statement:
Check whether a given binary tree is symmetric around its center.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print YES if symmetric, otherwise NO

Example:
Input:
7
1 2 2 3 4 4 3

Output:
YES

Explanation:
Left subtree is a mirror image of the right subtree.*/
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

        // Left child
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    free(queue);
    return root;
}

// Check whether two subtrees are mirrors
int isMirror(Node* left, Node* right) {
    // Both are NULL
    if (left == NULL && right == NULL)
        return 1;

    // One is NULL
    if (left == NULL || right == NULL)
        return 0;

    // Values must be equal
    if (left->data != right->data)
        return 0;

    // Check opposite children
    return isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

int isSymmetric(Node* root) {
    if (root == NULL)
        return 1;

    return isMirror(root->left, root->right);
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];

    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, N);

    if (isSymmetric(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}