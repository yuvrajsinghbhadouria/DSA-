/*
Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30 */
#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (heap[parent] <= heap[index])
                break;

            swap(heap[parent], heap[index]);
            index = parent;
        }
    }

    void heapifyDown(int index) {
        int n = heap.size();

        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < n && heap[left] < heap[smallest])
                smallest = left;

            if (right < n && heap[right] < heap[smallest])
                smallest = right;

            if (smallest == index)
                break;

            swap(heap[index], heap[smallest]);
            index = smallest;
        }
    }

public:
    void insert(int x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    void extractMin() {
        if (heap.empty()) {
            cout << -1 << endl;
            return;
        }

        cout << heap[0] << endl;

        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
            heapifyDown(0);
    }

    void peek() {
        if (heap.empty())
            cout << -1 << endl;
        else
            cout << heap[0] << endl;
    }
};

int main() {
    int N;
    cin >> N;

    MinHeap h;

    while (N--) {
        string op;
        cin >> op;

        if (op == "insert") {
            int x;
            cin >> x;
            h.insert(x);
        }
        else if (op == "extractMin") {
            h.extractMin();
        }
        else if (op == "peek") {
            h.peek();
        }
    }

    return 0;
}