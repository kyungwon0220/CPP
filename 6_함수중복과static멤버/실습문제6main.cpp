// ������ ũ���� �迭�� ��ȯ�ϴ� ���� 2���� static ��� �Լ��� ���� Arrayutility2 Ŭ������ �����, �� Ŭ������ �̿��Ͽ� �Ʒ� ����� ���� ��µǵ��� ���α׷��� �ۼ��϶�.

#include "�ǽ�����6.h"


int main() {
	int x[5], y[5], *z;
	int retSize;

	cout << "������ 5 �� �Է��϶�. �迭�� �����Ѵ�>>";
	for (int i = 0; i < 5; i++) cin >> x[i];
	cout << "������ 5 �� �Է��϶�. �迭�� �����Ѵ�>>";
	for (int i = 0; i < 5; i++) cin >> y[i];

	cout << "��ģ ���� �迭�� ����Ѵ�" << endl;
	for (unsigned short i = 0; i < 10; i++) cout << ArrayUtility2::concat(x, y, 5)[i] << ' ';
	cout << endl;

	z = ArrayUtility2::remove(x, y, 5, retSize);
	cout << "�迭 x[]���� y[]�� �� ����� ����Ѵ�. ������ " << retSize << endl;
	for (unsigned short i = 0; i < retSize; i++) cout << z[i] << ' ';
}