#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

Node* head = nullptr;

void insertAtPosition(int value, int pos) {
    Node* newNode = new Node(value);

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Invalid position\n";
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtPosition(int pos) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != nullptr; i++) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Invalid position\n";
        return;
    }

    Node* delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
}

void searchElement(int value) {
    Node* temp = head;
    int pos = 1;

    while (temp != nullptr) {
        if (temp->data == value) {
            cout << "Element found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }

    cout << "Element not found\n";
}

void countNodes() {
    Node* temp = head;
    int count = 0;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    cout << "Total nodes: " << count << endl;
}

void display() {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main() {
    int choice, value, pos;

    do {
        cout << "\n1. Insert at position\n";
        cout << "2. Delete at position\n";
        cout << "3. Search element\n";
        cout << "4. Count nodes\n";
        cout << "5. Display\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value and position: ";
            cin >> value >> pos;
            insertAtPosition(value, pos);
        }
        else if (choice == 2) {
            cout << "Enter position: ";
            cin >> pos;
            deleteAtPosition(pos);
        }
        else if (choice == 3) {
            cout << "Enter value to search: ";
            cin >> value;
            searchElement(value);
        }
        else if (choice == 4) {
            countNodes();
        }
        else if (choice == 5) {
            display();
        }
        else if (choice == 0) {
            break;
        }
        else {
            cout << "Invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}