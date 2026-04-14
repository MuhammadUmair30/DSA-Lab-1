#include <iostream>
using namespace std;

class Employee {
public:
	virtual void  calculateSalary() = 0;
};

class  FullTimeEmployee :public Employee {
	int salary;
public:
	FullTimeEmployee(int s) {
		salary = s;
	}
	void  calculateSalary() {
		cout << "The salary of full time employee is: " << salary << endl;
	}
	void display() {
		cout << "The salary of full time employee is: " << salary << endl;
	}
};

class PartTimeEmployee :public Employee {
	int hourrate;
	int workhour;
public:

	PartTimeEmployee(int h, int w) {

		hourrate = h;
		workhour = w;
	}

	void  calculateSalary() {
		cout << "The part time salary: " << hourrate * workhour << endl;
	
	}

	void display1() {
		cout << "The part time salary: " << hourrate * workhour << endl;
	}

};

int main() {

	FullTimeEmployee f1(5500);
	f1.display();
	PartTimeEmployee p1(20, 100);
	f1.display();

	return 0;
}