#include <iostream>
using namespace std;

class Queue {
private:
    int arr[100];
    int frontIndex, rear, size;

public:
    Queue() {
        frontIndex = 0;
        rear = -1;
        size = 0;
    }

    void enqueue(int value) {
        if (rear == 99) {
            cout << "Queue Overflow!\n";
            return;
        }
        arr[++rear] = value;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return -1;
        }
        int val = arr[frontIndex++];
        size--;
        return val;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return -1;
        }
        return arr[frontIndex];
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }

    void display() {
        for (int i = frontIndex; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class Stack {
private:
    int arr[100];
    int topIndex;

public:
    Stack() {
        topIndex = -1;
    }

    void push(int value) {
        arr[++topIndex] = value;
    }

    int pop() {
        return arr[topIndex--];
    }

    bool isEmpty() {
        return topIndex == -1;
    }
};

void reverseK(Queue& q, int k) {
    int n = q.getSize();

    if (k <= 1 || k > n) {
        return;
    }

    Stack s;

    for (int i = 0; i < k; i++) {
        s.push(q.dequeue());
    }

    while (!s.isEmpty()) {
        q.enqueue(s.pop());
    }

    for (int i = 0; i < n - k; i++) {
        q.enqueue(q.dequeue());
    }
}

int main() {
    Queue q;
    int n, value, k;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        q.enqueue(value);
    }

    cout << "Queue: ";
    q.display();

    cout << "Enter K: ";
    cin >> k;

    reverseK(q, k);

    cout << "Output: ";
    q.display();

    return 0;
}