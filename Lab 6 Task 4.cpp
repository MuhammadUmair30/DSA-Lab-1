#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string n) {
        name = n;
        next = nullptr;
    }
};

Node* head = nullptr;

void addPatient(string name) {
    Node* newNode = new Node(name);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void removePatient(string name) {
    if (head == nullptr) {
        cout << "No patients in queue\n";
        return;
    }

    if (head->name == name) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Patient removed\n";
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr && temp->name != name) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Patient not found\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Patient removed\n";
}

void displayPatients() {
    if (head == nullptr) {
        cout << "Queue is empty\n";
        return;
    }

    Node* temp = head;
    cout << "Patient Queue: ";

    while (temp != nullptr) {
        cout << temp->name << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

void countPatients() {
    Node* temp = head;
    int count = 0;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    cout << "Total patients: " << count << endl;
}

int main() {
    addPatient("Ali");
    addPatient("Sara");
    addPatient("Ahmed");
    addPatient("Ayesha");

    displayPatients();
    countPatients();

    removePatient("Ahmed");

    displayPatients();
    countPatients();

    removePatient("Ali");

    displayPatients();
    countPatients();

    return 0;
}