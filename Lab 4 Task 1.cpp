#include <iostream>
using namespace std;

template <typename T>
class AbstractQueue {
public:
    virtual void enQueue(T value) = 0;
    virtual T deQueue() = 0;
    virtual T front() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractQueue() {}
};

template <typename T>
class myQueue : public AbstractQueue<T> {
private:
    T* arr;
    int frontIndex;
    int rear;
    int size;
    int capacity;

public:
    myQueue(int cap) {
        capacity = cap;
        arr = new T[capacity];
        frontIndex = 0;
        rear = -1;
        size = 0;
    }

    void enQueue(T value) {
        if (isFull()) {
            cout << "Queue is Full! " << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
        cout << value << " inserted. " << endl;
    }

    T deQueue() {
        if (isEmpty()) {
            cout << "Queue is Empty! " << endl;
            return -1;
        }
        T value = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        size--;
        return value;
    }

    T front() const {
        if (isEmpty()) {
            cout << "Queue is Empty! " << endl;
            return -1;
        }
        return arr[frontIndex];
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is Empty! " << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(frontIndex + i) % capacity] << " ";
        }
        cout << endl;
    }

    ~myQueue() {
        delete[] arr;
    }
};


int main() {
    int cap;
    cout << "Enter Queue Size: ";
    cin >> cap;

    myQueue<int> q(cap);

    int choice = -1;
    int value;

    while (choice != 0) {
        cout << "\n===== QUEUE MENU =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check Empty" << endl;
        cout << "6. Check Full" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: "<< endl;
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            q.enQueue(value);
        }
        else if (choice == 2) {
            cout << "Removed: " << q.deQueue() << endl;
        }
        else if (choice == 3) {
            cout << "Front: " << q.front() << endl;
        }
        else if (choice == 4) {
            q.display();
        }
        else if (choice == 5) {
            if (q.isEmpty())
                cout << "Queue is Empty " << endl;
            else
                cout << "Queue is NOT Empty " << endl;
        }
        else if (choice == 6) {
            if (q.isFull())
                cout << "Queue is Full" << endl;
            else
                cout << "Queue is NOT Full " << endl;
        }
        else if (choice == 0) {
            cout << "Exiting..." << endl;
        }
        else {
            cout << "Invalid choice! " << endl;
        }
    }

    return 0;
} 