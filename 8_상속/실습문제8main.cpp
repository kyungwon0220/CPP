// ��� �����ʹ� �𵨸�(model), ������(manufacturer), �μ� �ż�(printedCount), �μ� ���� �ܷ�(availableCount)�� ��Ÿ���� ������ print(int pages) ��� �Լ��� ������, print()�� ȣ���� ������ pages ���� ������ ����Ѵ�.
// ��ũ�� �����ʹ� ��ũ �ܷ�(availableInk) ������ printInkJet(int pages) ��� �Լ��� �߰������� ������, ������ �����ʹ� ��� �ܷ�(availableToner) ������ ���� printLaser(int pages) ��� �Լ��� �߰������� ������.
// �� Ŭ������ ������ ���� �������� ��� ������ �Լ�, ������, �Ҹ��ڸ� �ۼ��ϰ�, ������ ���� ����ǵ��� ��ü ���α׷��� �ϼ��϶�.
// ��ũ�� ������ ��ü�� ������ ������ ��ü�� ���� �ϳ��� ���� �����Ͽ� �����Ѵ�.

#include "�ǽ�����8.h"


int main() {
	InkJetPrinter* inkjetp = new InkJetPrinter("Officejet V40", "HP", 5, 10);
	LaserPrinter* laserp = new LaserPrinter("SCX-6x45", "�Ｚ����", 3, 20);
	bool exit = true;

	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����" << endl;
	cout << "��ũ�� : ";
	inkjetp->show();
	cout << "������ : ";
	laserp->show();

	do {
		unsigned short needCount, sel;

		cout << endl << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
		
		cin >> sel >> needCount;

		switch (sel) {
		case 1: {
			inkjetp->printInkJet(needCount);
			inkjetp->show();
			laserp->show();

			char c;
			cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
			cin >> c;
			if (c == 'n') {
				exit = false;
				break;
			} else if (c == 'y') break;
		} // case1 end
		case 2: {
			laserp->printLaser(needCount);
			inkjetp->show();
			laserp->show();

			char c;
			cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
			cin >> c;
			if (c == 'n') {
				exit = false;
				break;
			}
			else if (c == 'y') break;
		} // case2 end
		default:
			break;
		}
	} while (exit);
} // main end