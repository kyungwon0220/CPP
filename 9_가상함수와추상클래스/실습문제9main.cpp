// ���� �׸��� ���� ��� ������ ���� Ŭ������ �����Ѵ�.
// ��� �����ʹ� �𵨸�(model), ������(manufacturer), �μ� �ż�(printedCount), �μ� ���� �ܷ�(availableCount)�� ��Ÿ���� ������ ������.
// print(int pages) �Լ��� show() �Լ��� ���� �Լ��� �����϶�.
// print(int pages)�� pages ��ŭ ����Ʈ �ϴ� �Լ��̰�, show() �Լ��� ���� ����Ʈ�� ��, ������, �μ� �ż�, �μ� ���� �ܷ� ���� ����ϴ� �Լ��̴�.
// ��ũ�� �����ʹ� ��ũ �ܷ�(availableInk) ������ �߰������� ������, ������ �����ʹ� ��� �ܷ�(availableToner) ������ �߰������� ������.
// �̵��� print(int pages) ��� �Լ��� ������ Ÿ�Կ� �°� �����϶�.
// �� Ŭ������ ���� �����ϰ� ������ ���� ����ǵ��� ��ü ���α׷��� �ϼ��϶�.
// InkJetPrinter ��ü�� LaserPrinter ��ü�� ���� �ϳ��� �������� �����Ͽ� �����Ѵ�.

#include "�ǽ�����9.h"

int main() {
	InkJetPrinter* IP = new InkJetPrinter("Officejet V40", "HP", 5, 10);
	LaserPrinter* LP = new LaserPrinter("SCX-6x45", "�Ｚ����", 3, 20);
	bool exit = true;

	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����." << endl;
	cout << "��ũ�� : ";
	IP->show();
	cout << "������ : ";
	LP->show();
	cout << endl;

	do {
		unsigned short sel, pages;
		char k;

		cout << endl << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
		cin >> sel >> pages;

		switch (sel) {
		case 1:
			IP->print(pages);
			break;
		case 2:
			LP->print(pages);
			break;
		default:
			break;
		}

		IP->show();
		LP->show();
		cout << "��� ����Ʈ �Ͻðڽ��ϱ�?(y/n)>>";
		cin >> k;
		if (k != 'y') exit = false;
	} while (exit);
}