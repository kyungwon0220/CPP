#include <iostream>

using namespace std;


class UI {
public:
	static unsigned short selMenu();
	static unsigned short selShape();
};


class Shape {
	Shape* next;
	
public:
	virtual void draw() = 0; // 순수 가상 함수
	Shape() {} // 생성자
	virtual ~Shape() {} // 가상 소멸자

	Shape* add(Shape* s) { this->next = s; return s; }
	Shape* getNext() { return this->next; }
	void setNext(Shape *s) { this->next = s->next; }
};


class Line : public Shape { // 선
	virtual void draw() { cout << "Line" << endl; }
public:
	virtual ~Line() {} // 가상 소멸자
};


class Circle : public Shape { // 원
	virtual void draw() { cout << "Circle" << endl; }
public:
	virtual ~Circle() {} // 가상 소멸자
};


class Rect : public Shape { // 사각형
	virtual void draw() { cout << "Rectangle" << endl; }
public:
	virtual ~Rect() {} // 가상 소멸자
};

class GraphicEditor {
	Shape* pStart;
	Shape* pLast;
	unsigned short count;
public:
	GraphicEditor() { cout << "그래픽 에디터입니다." << endl; this->count = 0; } // 생성자
	virtual ~GraphicEditor() {} // 가상 소멸자

	void start();
};