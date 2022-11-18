// �ǽ� ���� 7�� ������ �����غ���.
// ������ ���� Person Ŭ������ �ִ�.
// Person Ŭ������ main() �Լ��� �ۼ��Ͽ�, 3���� Person ��ü�� ������ �迭�� �����ϰ�, ������ ���� Ű���忡�� �̸��� ��ȭ��ȣ�� �Է¹޾� ����ϰ� �˻��ϴ� ���α׷��� �ϼ��϶�.


#include <iostream>
#include <string>

using namespace std;

class Person {
	string name;
	string tel;
public:
	Person() {}
	string getName() { return this->name; }
	string getTel() { return this->tel; }
	void set(string name, string tel) { this->name = name; this->tel = tel; }
};


int main() {
	string s;
	Person* p = new Person[3];
	int findex;
	string name, tel, searchN;


	cout << "�̸��� ��ȭ ��ȣ�� �Է��� �ּ���" << endl;

	for(unsigned short i=0; i<3; i++) {
		cout << "��� " << i + 1 << ">> ";
		getline(cin, s, '\n');

		findex = s.find(' ', 0); // ������ �ε���

		name = s.substr(0, findex);
		tel = s.substr(findex+1, s.length());

		p[i].set(name, tel);
	}


	cout << "��� ����� �̸��� ";

	for (unsigned short i = 0; i < 3; i++) cout << p[i].getName() << ' ';
	
	cout << "\n��ȭ��ȣ �˻��մϴ�. �̸��� �Է��ϼ���>>";

	cin >> searchN;

	for (unsigned short i = 0; i < 3; i++) {
		string tmpName = p[i].getName();

		if (tmpName == searchN) {
			cout << "��ȭ ��ȣ�� " << p[i].getTel() << endl;
			break;
		}
	}

	delete[] p;
}