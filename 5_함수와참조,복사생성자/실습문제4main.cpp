// �Ʒ��� ���� ������ �־��� bigger()�� �ۼ��ϰ� ����ڷκ��� 2���� ������ �Է¹޾� ū ���� ����ϴ� main()�� �ۼ��϶�.
// bigger()�� ���ڷ� �־��� a, b�� ������ true, �ƴϸ� false�� �����ϰ� ū ���� big�� �����϶�.


#include "�ǽ�����4.h"

int main() {
	int a, b, big;

	cout << "�� ������ �Է��ϼ���>> ";
	cin >> a >> b;

	if (bigger(a, b, big) == true) cout << "same" << endl;
	else cout << "ū ���� " << big << endl;
}