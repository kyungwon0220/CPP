// �ټ��� Ŭ������ �����ϰ� Ȱ���ϴ� ������ �����̴�. ���ϱ�(+), ����(-), ���ϱ�
// (*), ������(/)�� �����ϴ� 4���� Ŭ���� Add, Sub, Mul, Div�� ������� �Ѵ�. �̵�
// �� ��� �������� ���� ����� ������.
// - int Ÿ�� ���� a, b : �ǿ�����
// - void setValue(int x, int y) �Լ� : �Ű� ���� x, y�� ��� a, b�� ����
// - int calculate() �Լ� : ������ �����ϰ� ��� ����
// main() �Լ��� Add, Sub, Mul, Div Ŭ���� Ÿ���� ��ü a, s, m, d�� �����ϰ�, �Ʒ�
// �� ���� Ű����κ��� �� ���� ������ �����ڸ� �Է¹ް�, a, s, m, d ��ü �߿��� ��
// ���� ó���� ��ü�� setValue() �Լ��� ȣ���� ��, calculate()�� ȣ���Ͽ� �����
// ȭ�鿡 ����Ѵ�. ���α׷��� ���� ������ ����.
// Ŭ���� ����ο� �����θ� �и��ϰ�, ��� �ڵ带 �ǽ�����10.cpp ���Ͽ� �ۼ��϶�.
// Ŭ������ ����ο� �����θ� ��� ���ϰ� cpp ���Ϸ� ������ ���α׷��� �ۼ��϶�.
/*
* �� ������ �����ڸ� �Է��ϼ���>> 3 4 *
* 12
* �� ������ �����ڸ� �Է��ϼ���>> 5 2 /
* 2
* �� ������ �����ڸ� �Է��ϼ���>> 8 2 -
* 6
*/
#include <iostream>
#include "�ǽ�����10.h"

using namespace std;

int main() {
	int x, y;
	char value;

	while (1) {
		Add a;
		Sub s;
		Mul m;
		Div d;

		cout << "�� ������ �����ڸ� �Է��ϼ���>>";
		cin >> x >> y >> value;

		switch (value) {
		case '+':
			a.setValue(x, y);
			cout << a.calculate() << endl;
			break;
		case '-':
			s.setValue(x, y);
			cout << s.calculate() << endl;
			break;
		case '*':
			m.setValue(x, y);
			cout << m.calculate() << endl;
			break;
		case '/':
			d.setValue(x, y);
			cout << d.calculate() << endl;
			break;
		} // switch end
	} // while end
} // main end