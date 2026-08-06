/*Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
private:
    Node *front, *rear;

public:
    Queue() {
        front = rear = NULL;
    }

    // Enqueue operation
    void enqueue(int x) {
        Node* newNode = new Node(x);

        if (rear == NULL) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    // Dequeue operation
    void dequeue() {
        if (front == NULL) {
            cout << -1 << endl;
            return;
        }

        cout << front->data << endl;

        Node* temp = front;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }
};

int main() {
    int N;
    cin >> N;

    Queue q;

    while (N--) {
        string op;
        cin >> op;

        if (op == "enqueue") {
            int x;
            cin >> x;
            q.enqueue(x);
        }
        else if (op == "dequeue") {
            q.dequeue();
        }
    }

    return 0;
}