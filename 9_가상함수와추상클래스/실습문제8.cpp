// �簢���� �����ϴ� ������ ǥ���ϱ� ���� Shape Ŭ������ �ִ�.
// ���� 7�� �־��� Shape Ŭ������ �߻� Ŭ������ ����� ���� 7�� �ٽ� �ۼ��϶�.
// Shape�� �߻� Ŭ������ ������� getArea() �Լ��� ���� ���� �Լ��� ����� �ȴ�.

#include <iostream>

using namespace std;

class Shape {
protected:
	string name; // ������ �̸�
	int width, height; // ������ �����ϴ� �簢���� �ʺ�� ����
public:
	Shape(string n = "", int w = 0, int h = 0) { name = n; width = w; height = h; }
	virtual ~Shape() {} // �Ҹ��ڸ� ���� �Լ��� ����

	virtual double getArea() = 0; // dummy �� ����
	string getName() { return name; } // �̸� ����
};

class Oval : public Shape {
public:
	virtual double getArea() { return 3.14 * this->height * this->width; }

	Oval(string name, int w, int h) : Shape(name, w, h) {} // ������
	virtual ~Oval() {} // �Ҹ��ڸ� ���� �Լ��� ����
};

class Rect : public Shape {
public:
	virtual double getArea() { return this->height * this->width; }

	Rect(string name, int w, int h) : Shape(name, w, h) {} // ������
	virtual ~Rect() {} // �Ҹ��ڸ� ���� �Լ��� ����

};

class Triangular : public Shape {
public:
	virtual double getArea() { return (this->height * this->width) / 2; }

	Triangular(string name, int w, int h) : Shape(name, w, h) {} // ������
	virtual ~Triangular() {} // �Ҹ��ڸ� ���� �Լ��� ����

};


int main() {
	Shape* p[3];
	p[0] = new Oval("��붱", 10, 20);
	p[1] = new Rect("����", 30, 40);
	p[2] = new Triangular("�佺Ʈ", 30, 40);

	for (int i = 0; i < 3; i++) cout << p[i]->getName() << " ���̴� " << p[i]->getArea() << endl;

	for (int i = 0; i < 3; i++) delete p[i];
}