#include <iostream>
using namespace std;

class Stack {
private:
    int arr[100];
    int topIndex;

public:
    Stack() {
        topIndex = -1;
    }

    void push(int value) {
        if (topIndex == 99) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++topIndex] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return arr[topIndex--];
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }
};

class QueueUsingStack {
private:
    Stack s1, s2;

public:
    void enqueue(int value) {
        s1.push(value);
        cout << value << " inserted." << endl;
    }

    int dequeue() {
        if (s1.isEmpty() && s2.isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        if (s2.isEmpty()) {
            while (!s1.isEmpty()) {
                s2.push(s1.pop());
            }
        }

        return s2.pop();
    }

    int front() {
        if (s1.isEmpty() && s2.isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        if (s2.isEmpty()) {
            while (!s1.isEmpty()) {
                s2.push(s1.pop());
            }
        }

        return s2.top();
    }

    void display() {
        if (s1.isEmpty() && s2.isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        Stack temp1 = s1;
        Stack temp2 = s2;

        while (!temp2.isEmpty()) {
            cout << temp2.pop() << " ";
        }

        Stack reverse;
        while (!temp1.isEmpty()) {
            reverse.push(temp1.pop());
        }

        while (!reverse.isEmpty()) {
            cout << reverse.pop() << " ";
        }

        cout << endl;
    }
};

int main() {
    QueueUsingStack q;

    int choice = -1, value;

    while (choice != 0) {
        cout << "\n===== QUEUE USING STACK MENU =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front" << endl;
        cout << "4. Display" << endl;
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
        }
        else if (choice == 2) {
            cout << "Removed: " << q.dequeue() << endl;
        }
        else if (choice == 3) {
            cout << "Front: " << q.front() << endl;
        }
        else if (choice == 4) {
            q.display();
        }
        else if (choice == 0) {
            cout << "Exiting..." << endl;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}