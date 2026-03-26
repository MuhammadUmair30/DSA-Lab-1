#include <iostream>
#include <string>
using namespace std;

class ParkingLot {
    string myCarStack[8];
    int top = -1;
    int capacity = 8;

public:
    void parkCar(string car) {
        if (top == capacity - 1) {
            cout << "Parking Full\n";
            return;
        }
        top++;
        myCarStack[top] = car;
        cout << "Car Parked\n";
    }

    void removeCar(string car) {
        if (top == -1) {
            cout << "Parking Empty\n";
            return;
        }

        string tempStack[8];
        int tempTop = -1;
        bool found = false;

        while (top != -1) {
            if (myCarStack[top] == car) {
                top--;
                found = true;
                break;
            }
            else {
                tempTop++;
                tempStack[tempTop] = myCarStack[top];
                top--;
            }
        }

        while (tempTop != -1) {
            top++;
            myCarStack[top] = tempStack[tempTop];
            tempTop--;
        }

        if (found)
            cout << "Car Removed\n";
        else
            cout << "Car Not Found\n";
    }

    void displayCars() {
        if (top == -1) {
            cout << "No Cars Parked\n";
            return;
        }

        for (int i = top; i >= 0; i--) {
            cout << myCarStack[i] << endl;
        }
    }

    void totalCars() {
        cout << "Total Cars: " << top + 1 << endl;
    }

    void searchCar(string car) {
        bool found = false;

        for (int i = 0; i <= top; i++) {
            if (myCarStack[i] == car) {
                found = true;
                break;
            }
        }

        if (found)
            cout << "Car Found\n";
        else
            cout << "Car Not Found\n";
    }
};

int main() {
    ParkingLot p;
    int choice;
    string car;

    while (true) {
        cout << "\n1.Park Car\n2.Remove Car\n3.Display Cars\n4.Total Cars\n5.Search Car\n0.Exit\n";
        cin >> choice;

        if (choice == 0)
            break;

        if (choice == 1) {
            cout << "Enter Car Number: ";
            cin >> car;
            p.parkCar(car);
        }
        else if (choice == 2) {
            cout << "Enter Car Number: ";
            cin >> car;
            p.removeCar(car);
        }
        else if (choice == 3) {
            p.displayCars();
        }
        else if (choice == 4) {
            p.totalCars();
        }
        else if (choice == 5) {
            cout << "Enter Car Number: ";
            cin >> car;
            p.searchCar(car);
        }
    }

    return 0;
}