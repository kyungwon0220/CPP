// ������ ���� static ����� ���� Rando Ŭ������ �ϼ��϶�(Open Challenge ��Ʈ ����).
// �׸��� Random Ŭ������ �̿��Ͽ� ������ ���� ������ ���� ����ϴ� main() �Լ��� �ۼ��϶�.
// main()���� Random Ŭ������ seed() �Լ��� Ȱ���϶�.

#include "�ǽ�����7.h"


int main() {
	Random r;

	Random::seed();

	cout << "1���� 100���� ������ ���� 10���� ����մϴ�" << endl;

	for(unsigned short i = 0; i < 10; i++) cout << r.nextInt(0, 101) << ' ';
	cout << endl;

	cout << "���ĺ��� �����ϰ� 10���� ����մϴ�" << endl;
	for (unsigned short i = 0; i < 10; i++) cout << r.nextAlphabet() << ' ';
	cout << endl;

	cout << "������ �Ǽ��� 10���� ����մϴ�" << endl;
	for (unsigned short i = 0; i < 10; i++) cout << r.nextDouble() << ' ';
	cout << endl;
}
