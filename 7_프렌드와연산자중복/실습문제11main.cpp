// ���� Ŭ���� Stack�� ����� Ǫ��(push)������ << �����ڸ�, ��(pop)�� ���� >> �����ڸ�, ����ִ� ���������� �˱� ���� ! �����ڸ� �ۼ��϶�.
// ���� �ڵ带 main()���� �ۼ��϶�.

#include "�ǽ�����11.h"

int main() {
	Stack stack;
	stack << 3 << 5 << 10; // 3, 5, 10�� ������� Ǫ��
	while (true) {
		if (!stack) break; // ���� empty
		int x;
		stack >> x; // ������ ž�� �ִ� ���� ��
		cout << x << ' ';
	}
	cout << endl;
}