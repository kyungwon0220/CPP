// ��¥�� �ٷ�� Date Ŭ������ �ۼ��ϰ��� �Ѵ�.
// Date�� �̿��ϴ� main()�� ���� ����� ������ ����.
// Ŭ���� Date�� �ۼ��Ͽ� �Ʒ� ���α׷��� �߰��϶�.


#include "�ǽ�����2.h"

int main() {
	Date birth(2014, 3, 20); // 2014�� 3�� 20��
	Date independenceDay("1945/8/15/"); // 1945�� 8�� 15��

	independenceDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;
}