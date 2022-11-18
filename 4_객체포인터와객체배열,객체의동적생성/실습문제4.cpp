// ������ ���� Sample Ŭ������ �ִ�.
// ���� main() �Լ��� ����ǵ��� Sample Ŭ������ �ϼ��϶�.


#include <iostream>
#include <string>

using namespace std;

class Sample {
	int* p;
	int size;
public:
	Sample(int n) { // ������
		size = n; p = new int[n]; // n�� ���� �迭�� ���� ����
	}
	void read() { // ���� �Ҵ���� ���� �迭 p�� ����ڷκ��� ������ �Է� ����
		for (int i = 0; i < this->size; i++) cin >> this->p[i];
	}
	void write() { // ���� �迭�� ȭ�鿡 ���
		for (int i = 0; i < this->size; i++) cout << this->p[i] << ' ';
		cout << endl;
	}
	int big() { // ���� �迭���� ���� ū �� ����
		int big = this->p[0];

		for (int i = 0; i < this->size; i++)
			if (big < this->p[i]) big = this->p[i];

		cout << "���� ū ���� ";
		return big;
	}
	~Sample() { // �Ҹ���
		delete[] p;
	}
};


int main() {
	Sample s(10); // 10�� ���� �迭�� ���� Sample ��ü ����
	s.read(); // Ű���忡�� ���� �迭 �б�
	s.write(); // ���� �迭 ���
	cout << "���� ū ���� " << s.big() << endl; // ���� ū �� ���
}