// ������ �а��� ��Ÿ���� Dept Ŭ������ �̸� Ȱ���ϴ� main()�� ���� �ش�.
// main()�� ���� ����� ������ ���� �ǵ��� Dept Ŭ������ ������� ��� �����ϰ�, ��ü ���α׷��� �ϼ��϶�.
// Dept Ŭ������ ���� ������ Dept(const Dept& dept);�� �ۼ��Ǿ� ���� ���� ���, �������� ������ ���α׷� ���� ���� ���� �ð� ������ �߻��Ѵ�(���� �����ڸ� �� ä �����غ���).
// ���� �ڵ� ��� �κ��� ����� �� ���� �����ڰ� ȣ��Ǵ��� �����ϰ�, ���� �����ڰ� ������ �� ���� ������ �߻��ϴ��� �����϶�.
// Dept Ŭ������ ���� �����ڸ� �����϶�.
// ���� �����ڰ� ���� ��Ȳ������ ���� ������ �߻����� �ʰ� �Ϸ��� ��� �κ��� �����ϸ� �ɱ�? ���� �Ϻκ��� �������� �ذ�ȴ�.
// �ڵ带 �����غ���.

#include <iostream>

using namespace std;

class Dept {
	int size; // scores �迭�� ũ��
	int* scores; // ���� �Ҵ� ���� ���� �迭�� �ּ�
public:
	Dept(int size) {
		this->size = size;
		scores = new int[size];
	}
	Dept(const Dept& dept) { // ���� ������
		this->size = dept.size;
		this->scores = new int[size];

		for (unsigned short i = 0; i < dept.size; i++) this->scores[i] = dept.scores[i];
	}

	~Dept() {} // �Ҹ���

	int getSize() { return size; }

	void read() { // size ��ŭ Ű���忡�� ������ �о� scores �迭�� ����
		for (unsigned short i = 0; i < this->getSize(); i++) cin >> scores[i];
	}

	bool isOver60(int index) { // index�� �л��� ������ 60���� ũ�� true ����
		if (this->scores[index] > 60) return true;
		else return false;
	}
};

int countPass(Dept &dept) { // dept �а��� 60�� �̻����� ����ϴ� �л��� �� ����
	int count = 0;
	for (int i = 0; i < dept.getSize(); i++) if (dept.isOver60(i)) count++;
	return count;
}

int main() {
	Dept com(10); // �� 10���� �ִ� �а� com
	com.read(); // �� 10���� �л����� ������ Ű����κ��� �о� scores �迭�� ����
	int n = countPass(com); // com �а��� 60�� �̻����� ����� �л��� ���� ����
	cout << "60�� �̻��� " << n << "��";
}