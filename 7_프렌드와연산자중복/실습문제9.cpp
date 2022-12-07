// ���� �߻�ȭ�� Circle Ŭ������ ������ �Ʒ��� ����.
// ���� 8���� Circle ��ü�� ���� ���� ������ �����ϵ��� �����ڸ� �����϶�.

#include <iostream>

using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	void show() { cout << "radius = " << radius << " �� ��" << endl; }
	
	friend Circle operator+(int r, Circle c);
};

Circle operator+(int r, Circle c) { c.radius += r; return c; }

int main() {
	Circle a(5), b(4);
	b = 1 + a; // b�� �������� a�� �������� 1�� ���� ������ ����
	a.show();
	b.show();
}