/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20*/
#include <stdio.h>

#define MAX 1000

int pq[MAX];
int size = 0;

// Insert element
void insert(int x) {
    int i = size - 1;

    // Shift larger elements to the right
    while (i >= 0 && pq[i] > x) {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = x;
    size++;
}

// Delete highest priority (smallest element)
void deletePQ() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[0]);

    for (int i = 1; i < size; i++)
        pq[i - 1] = pq[i];

    size--;
}

// Peek highest priority element
void peek() {
    if (size == 0)
        printf("-1\n");
    else
        printf("%d\n", pq[0]);
}

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        char op[10];
        scanf("%s", op);

        if (op[0] == 'i') {
            int x;
            scanf("%d", &x);
            insert(x);
        }
        else if (op[0] == 'd') {
            deletePQ();
        }
        else if (op[0] == 'p') {
            peek();
        }
    }

    return 0;
}