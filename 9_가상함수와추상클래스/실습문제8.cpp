// 사각형에 내접하는 도형을 표혀하기 위한 Shape 클래스가 있다.
// 문제 7에 주어진 Shape 클래스를 추상 클래스로 만들고 문제 7을 다시 작성하라.
// Shape을 추상 클래스로 만들려면 getArea() 함수를 순수 가상 함수로 만들면 된다.

#include <iostream>

using namespace std;

class Shape {
protected:
	string name; // 도형의 이름
	int width, height; // 도형이 내접하는 사각형의 너비와 높이
public:
	Shape(string n = "", int w = 0, int h = 0) { name = n; width = w; height = h; }
	virtual ~Shape() {} // 소멸자를 가상 함수로 선언

	virtual double getArea() = 0; // dummy 값 리턴
	string getName() { return name; } // 이름 리턴
};

class Oval : public Shape {
public:
	virtual double getArea() { return 3.14 * this->height * this->width; }

	Oval(string name, int w, int h) : Shape(name, w, h) {} // 생성자
	virtual ~Oval() {} // 소멸자를 가상 함수로 선언
};

class Rect : public Shape {
public:
	virtual double getArea() { return this->height * this->width; }

	Rect(string name, int w, int h) : Shape(name, w, h) {} // 생성자
	virtual ~Rect() {} // 소멸자를 가상 함수로 선언

};

class Triangular : public Shape {
public:
	virtual double getArea() { return (this->height * this->width) / 2; }

	Triangular(string name, int w, int h) : Shape(name, w, h) {} // 생성자
	virtual ~Triangular() {} // 소멸자를 가상 함수로 선언

};


int main() {
	Shape* p[3];
	p[0] = new Oval("빈대떡", 10, 20);
	p[1] = new Rect("찰떡", 30, 40);
	p[2] = new Triangular("토스트", 30, 40);

	for (int i = 0; i < 3; i++) cout << p[i]->getName() << " 넓이는 " << p[i]->getArea() << endl;

	for (int i = 0; i < 3; i++) delete p[i];
}