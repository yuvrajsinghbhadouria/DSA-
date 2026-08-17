/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
6 2 8 0 4 7 9
2 8

Output:
6*/
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

Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

int findLCA(Node* root, int p, int q) {
    while (root != NULL) {

        // Both values are smaller
        if (p < root->data && q < root->data) {
            root = root->left;
        }

        // Both values are greater
        else if (p > root->data && q > root->data) {
            root = root->right;
        }

        // Values are on different sides or one is root
        else {
            return root->data;
        }
    }

    return -1;
}

int main() {
    int N;
    scanf("%d", &N);

    Node* root = NULL;

    // Build BST
    for (int i = 0; i < N; i++) {
        int value;
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Read two nodes
    int p, q;
    scanf("%d %d", &p, &q);

    printf("%d\n", findLCA(root, p, q));

    return 0;
}