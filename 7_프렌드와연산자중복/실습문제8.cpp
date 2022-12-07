// ���� �߻�ȭ�� Circle Ŭ������ ������ �Ʒ��� ����.
// ���� ������ �����ϵ��� �����ڸ� ������ �Լ��� �ۼ��϶�.

#include <iostream>

using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	void show() { cout << "radius = " << radius << " �� ��" << endl; }
	friend Circle operator++(Circle& c, int x);
	friend Circle& operator++(Circle& c);
	
};

Circle operator++(Circle& c, int x) { Circle tmp = c; c.radius++; return tmp; }
Circle& operator++(Circle& c) { c.radius++; return c; }

int main() {
	Circle a(5), b(4);
	++a; // �������� 1 ���� ��Ų��.
	b = a++; // �������� 1 ���� ��Ų��.
	a.show();
	b.show();
}