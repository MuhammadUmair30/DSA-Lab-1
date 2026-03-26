#include <iostream>
using namespace std;

class PrintQueue {
    string arr[100];
    int front, rear;

public:
    PrintQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(string doc) {
        if (rear == 99) {
            cout << "Queue is Full\n";
            return;
        }

        if (front == -1) front = 0;

        arr[++rear] = doc;
        cout << "Document added: " << doc << endl;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "No documents to print\n";
            return;
        }

        cout << "Printing: " << arr[front] << endl;
        front++;
    }

    void showFront() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Front document: " << arr[front] << endl;
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Documents in queue:\n";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    PrintQueue q;
    int choice = -1;
    string doc;

    while (choice != 0) {
        cout << "\n1. Add Document\n2. Print Document\n3. Check Front\n4. Display All\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter document name: ";
            cin >> doc;
            q.enqueue(doc);
        }
        else if (choice == 2) {
            q.dequeue();
        }
        else if (choice == 3) {
            q.showFront();
        }
        else if (choice == 4) {
            q.display();
        }
    }

    return 0;
}