#include <iostream>
using namespace std;

#define MAX 100

class Queue {
public:
    string arr[MAX];
    int front, rear;

    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    void enqueue(string x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = x;
    }

    string dequeue() {
        if (isEmpty()) {
            return "";
        }
        return arr[front++];
    }

    void display() {
        if (isEmpty()) {
            cout << "Empty\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

Queue EmergencyQueue, PassengerQueue, CargoQueue;

void enqueueFlight(string type, string id) {
    if (type == "Emergency") {
        EmergencyQueue.enqueue(id);
    }
    else if (type == "Passenger") {
        PassengerQueue.enqueue(id);
    }
    else if (type == "Cargo") {
        CargoQueue.enqueue(id);
    }
    else {
        cout << "Invalid flight type\n";
    }
}

void dequeueFlight() {
    if (!EmergencyQueue.isEmpty()) {
        cout << "Landing: " << EmergencyQueue.dequeue() << endl;
    }
    else if (!PassengerQueue.isEmpty()) {
        cout << "Landing: " << PassengerQueue.dequeue() << endl;
    }
    else if (!CargoQueue.isEmpty()) {
        cout << "Landing: " << CargoQueue.dequeue() << endl;
    }
    else {
        cout << "No flights waiting\n";
    }
}

void displayAll() {
    cout << "\nEmergency Queue: ";
    EmergencyQueue.display();

    cout << "Passenger Queue: ";
    PassengerQueue.display();

    cout << "Cargo Queue: ";
    CargoQueue.display();
}

int main() {
    int choice;
    string type, id;

    do {
        cout << "\n1.Enqueue Flight\n2.Dequeue (Land Flight)\n3.Display Queues\n4.Demo Sequence\n5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter flight type (Emergency/Passenger/Cargo): ";
            cin >> type;
            cout << "Enter flight ID: ";
            cin >> id;
            enqueueFlight(type, id);
        }
        else if (choice == 2) {
            dequeueFlight();
        }
        else if (choice == 3) {
            displayAll();
        }
        else if (choice == 4) {
            enqueueFlight("Passenger", "P1");
            enqueueFlight("Cargo", "C1");
            enqueueFlight("Emergency", "E1");
            enqueueFlight("Passenger", "P2");
            enqueueFlight("Cargo", "C2");
            enqueueFlight("Emergency", "E2");

            cout << "\nLanding Order:\n";
            while (!EmergencyQueue.isEmpty() || !PassengerQueue.isEmpty() || !CargoQueue.isEmpty()) {
                dequeueFlight();
            }
        }
        else if (choice == 5) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}