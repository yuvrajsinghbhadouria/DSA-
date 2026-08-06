/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations*/
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    deque<int> dq;

    // push_front()
    dq.push_front(20);

    // push_back()
    dq.push_back(30);
    dq.push_back(40);
    dq.push_front(10);

    cout << "Deque: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    // front()
    cout << "Front: " << dq.front() << endl;

    // back()
    cout << "Back: " << dq.back() << endl;

    // pop_front()
    dq.pop_front();

    // pop_back()
    dq.pop_back();

    cout << "After pop operations: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    // size()
    cout << "Size: " << dq.size() << endl;

    // empty()
    if (dq.empty())
        cout << "Deque is Empty" << endl;
    else
        cout << "Deque is Not Empty" << endl;

    // emplace_front()
    dq.emplace_front(5);

    // emplace_back()
    dq.emplace_back(50);

    cout << "After emplace: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    // erase()
    dq.erase(dq.begin() + 1);

    cout << "After erase: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    // resize()
    dq.resize(6, 100);

    cout << "After resize: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    // assign()
    dq.assign(5, 7);

    cout << "After assign: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    // reverse()
    reverse(dq.begin(), dq.end());

    cout << "After reverse: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    // sort()
    sort(dq.begin(), dq.end());

    cout << "After sort: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    // swap()
    deque<int> dq2 = {1, 2, 3};
    dq.swap(dq2);

    cout << "After swap, dq: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    // clear()
    dq.clear();

    cout << "After clear, Size: " << dq.size() << endl;

    return 0;
}