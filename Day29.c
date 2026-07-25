/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at end
void insertEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Function to rotate list right by k places
struct Node* rotateRight(struct Node *head, int k, int n) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    k = k % n;
    if (k == 0)
        return head;

    struct Node *last = head;
    while (last->next != NULL)
        last = last->next;

    // Make circular list
    last->next = head;

    int steps = n - k;
    struct Node *temp = head;

    // Traverse to (n-k)th node
    for (int i = 1; i < steps; i++)
        temp = temp->next;

    // New head
    head = temp->next;
    temp->next = NULL;

    return head;
}

// Function to print list
void printList(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, data, k;
    scanf("%d", &n);

    struct Node *head = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertEnd(&head, data);
    }

    scanf("%d", &k);

    head = rotateRight(head, k, n);

    printList(head);

    return 0;
}