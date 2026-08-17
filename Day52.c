/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
1 2 3 4 5 6 7
4 5

Output:
2*/
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

// Build tree from level-order traversal
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

// Find LCA in a normal Binary Tree
Node* findLCA(Node* root, int p, int q) {
    if (root == NULL)
        return NULL;

    // If current node is either p or q
    if (root->data == p || root->data == q)
        return root;

    // Search left subtree
    Node* left = findLCA(root->left, p, q);

    // Search right subtree
    Node* right = findLCA(root->right, p, q);

    // p and q are in different subtrees
    if (left != NULL && right != NULL)
        return root;

    // Return whichever side contains a node
    if (left != NULL)
        return left;

    return right;
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int p, q;
    scanf("%d %d", &p, &q);

    Node* root = buildTree(arr, N);

    Node* lca = findLCA(root, p, q);

    if (lca != NULL)
        printf("%d\n", lca->data);
    else
        printf("-1\n");

    return 0;
}