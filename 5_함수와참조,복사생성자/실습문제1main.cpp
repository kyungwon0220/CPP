// �� ���� Circle ��ü�� ��ȯ�ϴ� swap() �Լ��� '������ ���� ȣ��'�� �ǵ��� �ۼ��ϰ� ȣ���ϴ� ���α׷��� �ۼ��϶�.


#include "�ǽ�����1.h"

int main() {
	Circle c1(10), c2(20);

	swap(c1, c2);

	cout << c1.getRadius() << endl << c2.getRadius() << endl;
}