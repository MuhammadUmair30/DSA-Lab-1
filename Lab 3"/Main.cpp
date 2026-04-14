#include <iostream>
#include "myStack.h"

using namespace std;

void displayMenu() {
    cout << "Stack Operations Menu:" << endl;
    cout << "1. Push element" << endl;
    cout << "2. Pop element" << endl;
    cout << "3. Show top element" << endl;
    cout << "4. Check if stack is empty" << endl;
    cout << "5. Check if stack is full" << endl;
    cout << "6. Display stack elements" << endl;
    cout << "7. Show minimum element" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int maxSize;
    cout << "Enter the maximum size of the stack: ";
    cin >> maxSize;

    myStack<int> stack(maxSize);
    int choice;
    int value;

    while (true) {
        displayMenu();
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value to push: ";
            cin >> value;
            stack.push(value);
        }
        else if (choice == 2) {
            cout << "Popped value: " << stack.pop() << endl;
        }
        else if (choice == 3) {
            cout << "Top element: " << stack.top() << endl;
        }
        else if (choice == 4) {
            cout << "Stack is " << (stack.isEmpty() ? "empty" : "not empty") << "." << endl;
        }
        else if (choice == 5) {
            cout << "Stack is " << (stack.isFull() ? "full" : "not full") << "." << endl;
        }
        else if (choice == 6) {
            stack.display();
        }
        else if (choice == 7) {
            cout << "Minimum element in stack: " << stack.getMin() << endl;
        }
        else if (choice == 8) {
            cout << "Exiting program." << endl;
            break;
        }
        else {
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}