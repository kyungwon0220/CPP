// int Ÿ���� ������ ��üȭ�� Integer Ŭ������ �ۼ��϶�. Integer�� ��� ��� ��
// ���� �ڵ� �ζ������� �ۼ��϶�. Integer Ŭ������ Ȱ���ϴ� �ڵ�� ������ ����.
// ����2�� ��Ʈ�� �����ϰ� <string> ��� ������ stoi() �Լ��� �̿��ϸ� ���ϴ�.
/*
* 30 50 300 1
*/
#include <iostream>
#include "�ǽ�����8.h"

using namespace std;

int main() {
	Integer n(30);
	cout << n.get() << ' '; // 30 ���
	n.set(50);
	cout << n.get() << ' '; // 50 ���

	Integer m("300");
	cout << m.get() << ' '; // 300 ���
	cout << m.isEven(); // true(������ 1) ���
}