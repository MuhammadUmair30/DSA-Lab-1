#include <iostream>
using namespace std;

class Package {
public:
    int id;
    string address;
    int startTime;
    int endTime;
};

class DeliveryQueue {
    Package arr[100];
    int front, rear;

public:
    DeliveryQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int id, string addr, int s, int e) {
        if (rear == 99) {
            cout << "Queue Full\n";
            return;
        }

        if (front == -1) front = 0;

        rear++;
        arr[rear].id = id;
        arr[rear].address = addr;
        arr[rear].startTime = s;
        arr[rear].endTime = e;

        cout << "Package Added (ID: " << id << ")\n";
    }

    void showFront() {
        if (front == -1 || front > rear) {
            cout << "Queue Empty\n";
            return;
        }

        cout << "Front Package:\n";
        cout << "ID: " << arr[front].id << endl;
        cout << "Address: " << arr[front].address << endl;
        cout << "Time Window: " << arr[front].startTime
            << " - " << arr[front].endTime << endl;
    }

    void timeToDeliver(int currentTime) {
        if (front == -1 || front > rear) {
            cout << "Queue Empty\n";
            return;
        }

        if (currentTime >= arr[front].startTime && currentTime <= arr[front].endTime) {
            cout << "Package ID " << arr[front].id << " can be delivered now\n";
        }
        else {
            cout << "Package ID " << arr[front].id << " expired or not in time window\n";
            front++;
        }
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "No package to deliver\n";
            return;
        }

        cout << "Delivered Package ID: " << arr[front].id << endl;
        front++;
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue Empty\n";
            return;
        }

        cout << "\nPackages in Queue:\n";
        for (int i = front; i <= rear; i++) {
            cout << "ID: " << arr[i].id
                << ", Address: " << arr[i].address
                << ", Time: " << arr[i].startTime << "-" << arr[i].endTime
                << endl;
        }
    }
};

int main() {
    DeliveryQueue q;
    int choice = -1;

    while (choice != 0) {
        cout << "\n1. Add Package\n2. Deliver Package\n3. Check Front\n4. Display\n5. Check Time\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, s, e;
            string addr;

            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Address: ";
            cin >> addr;
            cout << "Enter Start Time: ";
            cin >> s;
            cout << "Enter End Time: ";
            cin >> e;

            q.enqueue(id, addr, s, e);
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
        else if (choice == 5) {
            int currentTime;
            cout << "Enter current time: ";
            cin >> currentTime;
            q.timeToDeliver(currentTime);
        }
    }

    return 0;
}