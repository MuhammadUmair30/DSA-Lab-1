#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string student;
    int priority;
    Node* next;

    Node(string s, int p) {
        student = s;
        priority = p;
        next = nullptr;
    }
};

class BookQueue {
private:
    string bookName;
    Node* head;

public:
    BookQueue(string name) {
        bookName = name;
        head = nullptr;
    }

    void addStudent(string name, int priority) {
        Node* newNode = new Node(name, priority);

        if (head == nullptr || priority > head->priority) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->priority >= priority) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void removeStudent(string name) {
        if (head == nullptr) {
            cout << "No reservations\n";
            return;
        }

        if (head->student == name) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Removed: " << name << endl;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && temp->student != name) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Student not found\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Removed: " << name << endl;
    }

    void updatePriority(string name, int newPriority) {
        if (head == nullptr) return;

        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && temp->student != name) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Student not found\n";
            return;
        }

        if (prev == nullptr)
            head = temp->next;
        else
            prev->next = temp->next;

        temp->priority = newPriority;
        temp->next = nullptr;

        if (head == nullptr || newPriority > head->priority) {
            temp->next = head;
            head = temp;
            return;
        }

        Node* cur = head;
        while (cur->next != nullptr && cur->next->priority >= newPriority) {
            cur = cur->next;
        }

        temp->next = cur->next;
        cur->next = temp;
    }

    void serveNext() {
        if (head == nullptr) {
            cout << "No reservations\n";
            return;
        }

        Node* temp = head;
        cout << "Serving: " << temp->student << endl;
        head = head->next;
        delete temp;
    }

    void display() {
        cout << "Book: " << bookName << endl;

        if (head == nullptr) {
            cout << "No reservations\n";
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->student << "(" << temp->priority << ") -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void count() {
        Node* temp = head;
        int c = 0;

        while (temp != nullptr) {
            c++;
            temp = temp->next;
        }

        cout << "Total students: " << c << endl;
    }
};

int main() {
    BookQueue book1("Data Structures");
    BookQueue book2("Operating Systems");

    book1.addStudent("Ali", 2);
    book1.addStudent("Sara", 3);
    book1.addStudent("Ahmed", 1);

    book2.addStudent("Ayesha", 2);
    book2.addStudent("Bilal", 1);
    book2.addStudent("Hina", 3);

    book1.display();
    book1.count();

    book2.display();
    book2.count();

    book1.updatePriority("Ahmed", 4);
    book1.display();

    book2.removeStudent("Bilal");
    book2.display();

    book1.serveNext();
    book1.display();

    return 0;
}