// ���� ���� 5���� �迭�� ���� �Ҵ�ް�, ������ 5�� �Է¹޾� ����� ���ϰ� ����� �� �迭�� �Ҹ��Ű���� main() �Լ��� �ۼ��϶�.

#include <iostream>

using namespace std;

int main() {
	int* i = new int[5];
	int sum = 0;

	cout << "���� 5�� �Է�>>";
	for (int j = 0; j < 5; j++) {
		cin >> i[j];
		sum += i[j];
	}

	cout << "��� " << (double)sum / 5;

	delete[] i;
}