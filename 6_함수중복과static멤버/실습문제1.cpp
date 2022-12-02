// add() �Լ��� ȣ���ϴ� main() �Լ��� ������ ����.
// (1) add() �Լ��� �ߺ� �ۼ��ϰ� ���α׷��� �ϼ��϶�.
// (2) ����Ʈ �Ű� ������ ���� �ϳ��� add() �Լ��� �ۼ��ϰ� ���α׷��� �ϼ��϶�.

#include <iostream>

using namespace std;

int add(int *p1, unsigned short size, int *p2 = NULL) { // NULL ��� nullptr�� �ϴ� ���� �ٶ�����
	int sum = 0;

	if (p2) for (unsigned short i = 0; i < size; i++) sum += p2[i] + p1[i];
	else for (unsigned short i = 0; i < size; i++) sum += p1[i];
	
	return sum;
}
int main() {
	int a[] = { 1,2,3,4,5 };
	int b[] = { 6,7,8,9,10 };
	int c = add(a, 5); // �迭 a�� ������ ��� ���� �� ����
	int d = add(a, 5, b); // �迭 a�� b�� ������ ��� ���� �� ����
	cout << c << endl; // 15 ���
	cout << d << endl; // 55  ���
}