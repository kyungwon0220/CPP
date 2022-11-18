// �������� Person�� �����, Family�� ������ �߻�ȭ�� Ŭ�����μ� �ϼ����� ���� Ŭ�����̴�.
// ���� main()�� �۵��ϵ��� Person�� Family Ŭ������ �ʿ��� ������� �߰��ϰ� �ڵ带 �ϼ��϶�.


#include <iostream>

using namespace std;


class Person {
	string name;
public:
	Person() { this->name = ""; }
	Person(string name) { this->name = name; }
	string getName() { return this->name; }
	void setName(string name) { this->name = name; }
};

class Family {
	Person* p; // Person �迭 ������
	int size; // Person �迭�� ũ��. ���� ������ ��
	string name;
public:
	Family(string name, int size) { // size ������ŭ Person �迭 ���� ����
		this->size = size;
		this->name = name;

		p = new Person[size];
	}

	void show() { // ��� ���� ������ ���
		cout << this->name << "������ ������ ���� " << size << "�� �Դϴ�." << endl;
		for (unsigned short i = 0; i < size; i++) cout << this->p[i].getName() << "\t";
	}

	void setName(unsigned short i, string name) {
		this->p[i].setName(name);
	}

	~Family() { delete[] p; }
};


int main() {
	Family* simpson = new Family("Simpson", 3); // 3������ ������ Simpson ����
	simpson->setName(0, "Mr. Simpson");
	simpson->setName(1, "Mrs. Simpson");
	simpson->setName(2, "Bart Simpson");
	simpson->show();
	delete simpson;
}