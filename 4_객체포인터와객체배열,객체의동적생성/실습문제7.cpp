// ������ ���� ���� �߻�ȭ�� Circle Ŭ������ �ִ�.
// Circle Ŭ������ main() �Լ��� �ۼ��ϰ� 3���� Circle ��ü�� ���� �迭�� �����ϰ�, ������ ���� �Է¹ް� ������ 100���� ū ���� ������ ����ϴ� ���α׷��� �ϼ��϶�.
// circle Ŭ������ �ϼ��϶�.

class Circle {
	int radius; // ���� ������ ��
public:
	void setRadius(int radius) { this->radius = radius; } // �������� �����Ѵ�.
	double getArea() { return this->radius * this->radius * 3.14; } // ������ �����Ѵ�.
};


#include <iostream>

using namespace std;


int main() {
	Circle* c = new Circle[3];
	int radius;
	unsigned short count = 0;

	for (unsigned short i = 0; i < 3; i++) {
		cout << "�� " << i + 1 << "�� ������ >> ";
		cin >> radius;
		c[i].setRadius(radius);
		if (c[i].getArea() > 100.0) count++;
	}

	cout << "������ 100���� ū ���� " << count << "�� �Դϴ�";

	delete[] c;
}