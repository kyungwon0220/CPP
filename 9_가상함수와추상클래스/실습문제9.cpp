#include "�ǽ�����9.h"

void InkJetPrinter::print(int pages) {
	if (pages > this->availableCount) cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
	else {
		if (availableInk < pages) cout << "��ũ�� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
		else {
			this->availableCount -= pages;
			availableInk -= pages;
			cout << "����Ʈ�Ͽ����ϴ�." << endl;
		}
	}
}

void InkJetPrinter::show() { cout << this->getName() << " ," << this->getManufacturer() << " ," << this->availableCount << "�� ,���� ��ũ " << this->availableInk << endl; }


void LaserPrinter::print(int pages) {
	if (pages > this->availableCount) cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
	else {
		if (availableToner < 1) cout << "��ʰ� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
		else {
			this->availableCount -= pages;
			availableToner -= 1;
			cout << "����Ʈ�Ͽ����ϴ�." << endl;
		}			
	}
}

void LaserPrinter::show() { cout << this->getName() << " ," << this->getManufacturer() << " ," << this->availableCount << "�� ,������� " << this->availableToner << endl; }
