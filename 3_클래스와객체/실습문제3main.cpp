// ���࿡�� ����ϴ� ���α׷��� �ۼ��ϱ� ����, ���� ���� �ϳ��� ǥ���ϴ� Ŭ����
// Account�� �ʿ��ϴ�. ���� ������ ������ ����, ���� ��ȣ, �ܾ��� ��Ÿ���� 3 ���
// ������ �̷������. main() �Լ��� ���� ����� ������ ������ Account Ŭ������ ��
// ���϶�.
// Account�� name, id, balance(�ܾ�)�� 3 ��� ������ ������, getOwner(), deposit(),
// withdraw(), inquiry()�� 3 ��� �Լ��� ������ Ŭ������ ����� �ȴ�.

/*
* Kiate�� �ܾ��� 55000
* Kitae�� �ܾ��� 35000
*/
#include <iostream>
#include "�ǽ�����3.h"

using namespace std;

int main() {
	Account a("kitae", 1, 5000); // id 1��, �ܾ� 5000��, �̸��� kitae�� ���� ����
	a.deposit(50000); // 50000�� ����
	cout << a.getOwner() << "�� �ܾ��� " << a.inquiry() << endl;
	unsigned long money = a.withdraw(20000); // 20000�� ���. withdraw()�� ����� ���� �ݾ� ����
	cout << a.getOwner() << "�� �ܾ��� " << a.inquiry() << endl;
}