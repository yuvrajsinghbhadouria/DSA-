/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10*/
#include <stdio.h>

#define MAX 100

// Stack
int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

// Queue
int queue[MAX];
int front = 0, rear = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int main() {
    int n, i;

    scanf("%d", &n);

    // Read queue elements
    for(i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    // Move queue to stack
    while(front <= rear) {
        push(dequeue());
    }

    // Move stack back to queue
    front = 0;
    rear = -1;

    while(!isEmpty()) {
        enqueue(pop());
    }

    // Print reversed queue
    for(i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}