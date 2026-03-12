//#include <iostream>
//using namespace std;
//
//class shape {
//public:
//	virtual void area() = 0;
//
//};
//
//class circle :public shape {
//
//	int radius;
//public:
//
//	circle(int r) {
//		radius = r;
//	}
//	void area() {
//		cout << "The area of circle is: " << 3.14 * radius * radius << endl;
//	}
//
//	void display() {
//		cout << "The area of circle is: " << 3.14 * radius * radius << endl;
//	}
//};
//
//class rectangle :public shape {
//	int length, width;
//public:
//	rectangle(int l, int w) {
//		length = l;
//		width = w;
//	}
//	void area() {
//		cout << "The area of rectangle is: " << length*width << endl;
//	}
//
//	void display1() {
//		cout << "The area of rectangle is: " << length * width << endl;
//	}
//
//};
//
//int main() {
//
//	circle c1(5);
//	c1.display();
//	rectangle r1(4, 6);
//	r1.display1();
//
//	return 0;
//
//}