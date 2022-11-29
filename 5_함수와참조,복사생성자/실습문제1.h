#include <iostream>

using namespace std;

class Circle {
	double radius;
public:
	Circle();
	Circle(double rad);
	Circle(const Circle& c);
	double getRadius();
};

void swap(Circle& c1, Circle& c2);