// �ǽ� ���� 7�� ������ �����غ���.
// ����ڷκ��� ������ ���� ���� ������ �Է¹ް�, ���� ������ŭ �������� �Է¹޴� ������� �����϶�.
// ���� ������ ���� �������� �迭�� �Ҵ�޾ƾ� �Ѵ�.

class Circle {
	int radius; // ���� ������ ��
public:
	void setRadius(int radius) { this->radius = radius; } // �������� �����Ѵ�.
	double getArea() { return this->radius * this->radius * 3.14; } // ������ �����Ѵ�.
};


#include <iostream>

using namespace std;


int main() {
	unsigned short size;
	int radius;
	unsigned short count = 0;

	cout << "���� ���� >> ";
	cin >> size;

	Circle* c = new Circle[size];

	for (unsigned short i = 0; i < size; i++) {
		cout << "�� " << i + 1 << "�� ������ >> ";
		cin >> radius;
		c[i].setRadius(radius);
		if (c[i].getArea() > 100.0) count++;
	}

	cout << "������ 100���� ū ���� " << count << "�� �Դϴ�";

	delete[] c;
}