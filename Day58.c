/*Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree

Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1

Explanation:
Preorder identifies root, inorder splits left and right subtrees.*/
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

int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }

    return -1;
}

Node* buildTree(int preorder[], int inorder[],
                int inStart, int inEnd, int* preIndex) {

    if (inStart > inEnd)
        return NULL;

    // First element of preorder is the root
    int rootValue = preorder[*preIndex];
    (*preIndex)++;

    Node* root = createNode(rootValue);

    // Find root in inorder
    int rootIndex = findIndex(inorder, inStart, inEnd, rootValue);

    // Build left subtree
    root->left = buildTree(preorder, inorder,
                           inStart, rootIndex - 1, preIndex);

    // Build right subtree
    root->right = buildTree(preorder, inorder,
                            rootIndex + 1, inEnd, preIndex);

    return root;
}

void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int N;
    scanf("%d", &N);

    int preorder[N];
    int inorder[N];

    // Read preorder
    for (int i = 0; i < N; i++)
        scanf("%d", &preorder[i]);

    // Read inorder
    for (int i = 0; i < N; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;

    Node* root = buildTree(preorder, inorder,
                           0, N - 1, &preIndex);

    // Print postorder
    postorder(root);

    printf("\n");

    return 0;
}