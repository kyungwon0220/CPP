// Ŭ���� Accumulator�� add() �Լ��� ���� ��� ���� �����ϴ� Ŭ�����μ�, ������ ���� ����ȴ�.
// Accumulator Ŭ������ �����϶�.
// Accumulator�� ������ ���� main() �Լ��� ���� Ȱ��ȴ�.


#include <iostream>

using namespace std;

class Accumulator {
	int value;
public:
	Accumulator(int value) { this->value = value; } // �Ű� ���� value�� ��� value�� �ʱ�ȭ�Ѵ�.
	Accumulator& add(int n) { this->value += n; return *this; } // value�� n�� ���� ���� �����Ѵ�.
	int get() { return this->value; } // ������ �� value�� �����Ѵ�.
};

int main() {
	Accumulator acc(10);
	acc.add(5).add(6).add(7); // acc�� value ����� 28�� �ȴ�.
	cout << acc.get(); // 28 ���
}