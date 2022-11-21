// ������ �̸��� �������� �Ӽ����� ���� Circle Ŭ������ �̵��� �迭�� �����ϴ� CircleManager Ŭ�����̴�.
// Ű���忡�� ���� ������ �Է¹ް�, �� ������ŭ ���� �̸��� �������� �Է¹ް�, ������ ���� ����ǵ��� main() �Լ��� �ۼ��϶�.
// Circle, CircleManager Ŭ������ �ϼ��϶�.


#include <iostream>
#include <string>

using namespace std;

class Circle {
	int radius; // ���� ������ ��
	string name; // ���� �̸�
public:
	void setCircle(string name, int radius) { this->name = name; this->radius = radius; } // �̸��� ������ ����
	double getArea() { return this->radius * this->radius * 3.14; }
	string getName() { return this->name; }
};


class CircleManager {
	Circle* p; // Circle �迭�� ���� ������
	int size; // �迭�� ũ��
public:
	CircleManager(int size) { // size ũ���� �迭�� ���� ����. ����ڷκ��� �Է� �Ϸ�
		this->size = size;
		p = new Circle[size];

		string inputs;
		int findex;
		for (int i = 0; i < size; i++) {
			cout << "�� " << i + 1 << "�� �̸��� ������ >> ";
			getline(cin, inputs, '\n');
			findex = inputs.find(' ', 0); // ������ �ε��� ��
			p[i].setCircle(inputs.substr(0, findex), stoi(inputs.substr(findex)));
		}
	}

	void searchByName(const string name) { // ����ڷκ��� ���� �̸��� �Է¹޾� ���� ���
		for (unsigned short i = 0; i < this->size; i++)
			if (name.compare(p[i].getName()) == 0)
				cout << p[i].getName() << "�� ������ " << p[i].getArea() << endl;
	}

	void searchByArea(const int area) { // ����ڷκ��� ������ �Է¹޾� �������� ū ���� �̸� ���
		cout << area << "���� ū ���� �˻��մϴ�." << endl;

		for (unsigned short i = 0; i < this->size; i++) {
			if ((int)area < p[i].getArea())
				cout << p[i].getName() << "�� ������ " << p[i].getArea() << ", ";
		}
	}


	~CircleManager() { delete[] p; }
};


int main() {
	int N;
	string inputs, name, searchArea;

	cout << "���� ���� >> ";
	cin >> N;
	cin.ignore(); // ���Է½� ERR (���� ����

	CircleManager manager(N);

	cout << "�˻��ϰ��� �ϴ� ���� �̸� >> ";
	cin >> name;
	manager.searchByName(name);

	cout << "�ּ� ������ ������ �Է��ϼ��� >> ";
	cin >> searchArea;
	manager.searchByArea(stoi(searchArea));
}