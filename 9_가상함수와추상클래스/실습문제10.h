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
	virtual void draw() = 0; // ���� ���� �Լ�
	Shape() {} // ������
	virtual ~Shape() {} // ���� �Ҹ���

	Shape* add(Shape* s) { this->next = s; return s; }
	Shape* getNext() { return this->next; }
	void setNext(Shape *s) { this->next = s->next; }
};


class Line : public Shape { // ��
	virtual void draw() { cout << "Line" << endl; }
public:
	virtual ~Line() {} // ���� �Ҹ���
};


class Circle : public Shape { // ��
	virtual void draw() { cout << "Circle" << endl; }
public:
	virtual ~Circle() {} // ���� �Ҹ���
};


class Rect : public Shape { // �簢��
	virtual void draw() { cout << "Rectangle" << endl; }
public:
	virtual ~Rect() {} // ���� �Ҹ���
};

class GraphicEditor {
	Shape* pStart;
	Shape* pLast;
	unsigned short count;
public:
	GraphicEditor() { cout << "�׷��� �������Դϴ�." << endl; this->count = 0; } // ������
	virtual ~GraphicEditor() {} // ���� �Ҹ���

	void start();
};