Problem: BST Search

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
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

Node* search(Node* root, int value) {
    if (root == NULL)
        return NULL;

    if (root->data == value)
        return root;

    if (value < root->data)
        return search(root->left, value);

    return search(root->right, value);
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
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

    // Value to search
    int value;
    scanf("%d", &value);

    Node* result = search(root, value);

    if (result == NULL) {
        printf("-1\n");
    } else {
        inorder(result);
        printf("\n");
    }

    return 0;
}