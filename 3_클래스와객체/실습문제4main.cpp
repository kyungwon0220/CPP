// CoffeeMachine Ŭ������ ������. main() �Լ��� ���� ����� ������ ������
// CoffeeMachine Ŭ������ �ۼ��϶�. ���������� �� �ܿ��� Ŀ�ǿ� ���� ���� 1�� ��
// ��ǰ�, �Ƹ޸�ī���� ��� Ŀ�Ǵ� 1, ���� 2�� �Һ�ǰ�, ���� Ŀ�Ǵ� Ŀ��1, ��2,
// ���� 1�� �Һ�ȴ�. CoffeeMachine Ŭ�������� � ��� ������ � ��� �Լ���
// �ʿ����� �� �Ǵ��Ͽ� �ۼ��϶�.
/*
* Ŀ�� �ӽ� ����, Ŀ��:4 ��:9 ����:3 // java.show();�� ���� ���
* Ŀ�� �ӽ� ����, Ŀ��:3 ��:7 ����:3
* Ŀ�� �ӽ� ����, Ŀ��:2 ��:5 ����:2
* Ŀ�� �ӽ� ����, Ŀ��:10 ��:10 ����:10
*/

#include "�ǽ�����4.h"

int main() {
	CoffeeMachine java(5, 10, 3);
	java.drinkEspresso();
	java.show();
	java.drinkAmericano();
	java.show();
	java.drinkSugarCoffee();
	java.show();
	java.fill();
	java.show();
}