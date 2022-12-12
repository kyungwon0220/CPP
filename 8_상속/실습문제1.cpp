// ���� 1~2�� ����Ǵ� ���� �߻�ȭ�� Circle Ŭ������ �ִ�.
// ���� �ڵ尡 ����ǵ��� Circle�� ��ӹ��� NamedCircle Ŭ������ �ۼ��ϰ� ��ü ���α׷��� �ϼ��϶�.

#include <iostream>

using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

class NamedCircle : private Circle {
	string name;
public:
	NamedCircle(int radius, string name) : Circle(radius) { this->name = name; }
	string getName() { return this->name; }
	void show() { cout << "�������� " << this->getRadius() << "�� " << this->getName() << endl; }
};

int main() {
	NamedCircle waffle(3, "waffle"); // �������� 3�̰� �̸��� waffle�� ��
	waffle.show();
}