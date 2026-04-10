#include <iostream>
using namespace std;

struct Node {
    int roll;
    string name;
    float marks;
    Node* next;
};

Node* head = NULL;

Node* createNode(int roll, string name, float marks) {
    Node* newNode = new Node;
    newNode->roll = roll;
    newNode->name = name;
    newNode->marks = marks;
    newNode->next = NULL;
    return newNode;
}

void insertBeginning(int roll, string name, float marks) {
    Node* newNode = createNode(roll, name, marks);
    newNode->next = head;
    head = newNode;
}

void insertEnd(int roll, string name, float marks) {
    Node* newNode = createNode(roll, name, marks);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAfter(int key, int roll, string name, float marks) {
    Node* temp = head;
    while (temp != NULL && temp->roll != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Roll number not found\n";
        return;
    }
    Node* newNode = createNode(roll, name, marks);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteStudent(int roll) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    if (head->roll == roll) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted successfully\n";
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->roll != roll) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Student not found\n";
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
    cout << "Deleted successfully\n";
}

void display() {
    if (head == NULL) {
        cout << "No records\n";
        return;
    }

    Node* temp = head;
    cout << "\nRoll\tName\tMarks\n";
    while (temp != NULL) {
        cout << temp->roll << "\t" << temp->name << "\t" << temp->marks << endl;
        temp = temp->next;
    }
}

void search(int roll) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->roll == roll) {
            cout << "Found: " << temp->roll << " " << temp->name << " " << temp->marks << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Student not found\n";
}

void update(int roll) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->roll == roll) {
            cout << "Enter new name: ";
            cin >> temp->name;
            cout << "Enter new marks: ";
            cin >> temp->marks;
            cout << "Updated successfully\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Student not found\n";
}

void statistics() {
    if (head == NULL) {
        cout << "No data available\n";
        return;
    }

    Node* temp = head;
    float maxMarks = temp->marks;
    float minMarks = temp->marks;
    float sum = 0;
    int count = 0;

    while (temp != NULL) {
        if (temp->marks > maxMarks) maxMarks = temp->marks;
        if (temp->marks < minMarks) minMarks = temp->marks;
        sum += temp->marks;
        count++;
        temp = temp->next;
    }

    cout << "Highest Marks: " << maxMarks << endl;
    cout << "Lowest Marks: " << minMarks << endl;
    cout << "Average Marks: " << sum / count << endl;
}

int main() {
    int choice, roll, key;
    string name;
    float marks;

    do {
        cout << "\n1.Insert Beginning\n2.Insert End\n3.Insert After\n4.Delete\n5.Display\n6.Search\n7.Update\n8.Statistics\n9.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter roll, name, marks: ";
            cin >> roll >> name >> marks;
            insertBeginning(roll, name, marks);
        }
        else if (choice == 2) {
            cout << "Enter roll, name, marks: ";
            cin >> roll >> name >> marks;
            insertEnd(roll, name, marks);
        }
        else if (choice == 3) {
            cout << "Insert after roll: ";
            cin >> key;
            cout << "Enter roll, name, marks: ";
            cin >> roll >> name >> marks;
            insertAfter(key, roll, name, marks);
        }
        else if (choice == 4) {
            cout << "Enter roll to delete: ";
            cin >> roll;
            deleteStudent(roll);
        }
        else if (choice == 5) {
            display();
        }
        else if (choice == 6) {
            cout << "Enter roll to search: ";
            cin >> roll;
            search(roll);
        }
        else if (choice == 7) {
            cout << "Enter roll to update: ";
            cin >> roll;
            update(roll);
        }
        else if (choice == 8) {
            statistics();
        }
        else if (choice == 9) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice\n";
        }

    } while (choice != 9);

    return 0;
}