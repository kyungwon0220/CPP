// ���� 1~2�� ����Ǵ� ���� �߻�ȭ�� Circle Ŭ������ �ִ�.
// ������ ���� �迭�� �����Ͽ� ���� ���� ����� �������� Circle�� ��ӹ��� NamedCircle Ŭ������ main() �Լ� �� �ʿ��� �Լ��� �ۼ��϶�.

#include <iostream>
#include <string>

using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

class NamedCircle : public Circle {
	string name;
public:
	NamedCircle(int radius=0, string name="") : Circle(radius) { this->name = name; }
	string getName() { return this->name; }
	void setName(string name) { this->name = name; }
	void show() { cout << "�������� " << this->getRadius() << "�� " << this->getName() << endl; }
};

int main() {
	NamedCircle pizza[5];
	int max;
	unsigned short check;

	cout << "5 ���� ���� �������� ���� �̸��� �Է��ϼ���" << endl;

	for(unsigned short i=0; i<5; i++) {
		cout << i + 1 << ">> ";
		
		int r;
		cin >> r;

		string name;
		getline(cin, name);

		pizza[i].setRadius(r);
		pizza[i].setName(name);
	}

	max = pizza[0].getRadius();
	
	for (unsigned short i = 1; i < 5; i++) {
		if (max < pizza[i].getRadius()) {
			check = i;
			max = pizza[i].getRadius();
		}
	}

	cout << "���� ������ ū ���ڴ� " << pizza[check].getName() << "�Դϴ�" << endl;
}