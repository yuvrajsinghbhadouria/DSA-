/*Problem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree

Example:
Input:
5
4 2 5 1 3
4 5 2 3 1

Output:
1 2 4 5 3

Explanation:
Postorder gives root at end, inorder divides left and right subtrees.*/
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

int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }

    return -1;
}

Node* buildTree(int inorder[], int postorder[],
                int inStart, int inEnd, int *postIndex) {

    if (inStart > inEnd)
        return NULL;

    // Last element of postorder is the root
    int rootValue = postorder[*postIndex];
    (*postIndex)--;

    Node* root = createNode(rootValue);

    // Find root in inorder
    int rootIndex = findIndex(inorder, inStart, inEnd, rootValue);

    /*
       Since postorder is processed from right to left,
       build RIGHT subtree first.
    */
    root->right = buildTree(inorder, postorder,
                            rootIndex + 1, inEnd, postIndex);

    root->left = buildTree(inorder, postorder,
                           inStart, rootIndex - 1, postIndex);

    return root;
}

void preorder(Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);

    preorder(root->left);
    preorder(root->right);
}

int main() {
    int N;
    scanf("%d", &N);

    int inorder[N];
    int postorder[N];

    // Read inorder
    for (int i = 0; i < N; i++)
        scanf("%d", &inorder[i]);

    // Read postorder
    for (int i = 0; i < N; i++)
        scanf("%d", &postorder[i]);

    int postIndex = N - 1;

    Node* root = buildTree(inorder, postorder,
                           0, N - 1, &postIndex);

    // Print preorder traversal
    preorder(root);

    printf("\n");

    return 0;
}