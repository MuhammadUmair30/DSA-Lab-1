#include <iostream>
using namespace std;

class TicketQueue {
private:
    int arr[100];
    int frontIndex, rear, size;

public:
    TicketQueue() {
        frontIndex = 0;
        rear = -1;
        size = 0;
    }

    void enqueue(int ticket_id) {
        if (rear == 99) {
            cout << "Queue Overflow! Cannot add more tickets.\n";
            return;
        }

        if (ticket_id < 1000 || ticket_id > 9999) {
            cout << "Invalid Ticket ID! Must be 4-digit.\n";
            return;
        }

        arr[++rear] = ticket_id;
        size++;
        cout << "Ticket " << ticket_id << " added.\n";
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "No tickets to resolve.\n";
            return -1;
        }

        int ticket = arr[frontIndex++];
        size--;
        cout << "Ticket " << ticket << " resolved.\n";
        return ticket;
    }

    int front() {
        if (isEmpty()) {
            cout << "No pending tickets.\n";
            return -1;
        }
        return arr[frontIndex];
    }

    bool isEmpty() {
        return size == 0;
    }

    void display() {
        if (isEmpty()) {
            cout << "No pending tickets.\n";
            return;
        }

        cout << "Pending Tickets: ";
        for (int i = frontIndex; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    TicketQueue q;
    int choice = -1, ticket_id;

    while (choice != 0) {
        cout << "\n===== CUSTOMER SUPPORT SYSTEM =====\n";
        cout << "1. Add Ticket\n";
        cout << "2. Resolve Ticket\n";
        cout << "3. View Next Ticket\n";
        cout << "4. Display All Tickets\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter 4-digit Ticket ID: ";
            cin >> ticket_id;
            q.enqueue(ticket_id);
        }
        else if (choice == 2) {
            q.dequeue();
        }
        else if (choice == 3) {
            int t = q.front();
            if (t != -1)
                cout << "Next Ticket: " << t << endl;
        }
        else if (choice == 4) {
            q.display();
        }
        else if (choice == 0) {
            cout << "Exiting system...\n";
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}