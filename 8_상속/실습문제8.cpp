#include "�ǽ�����8.h"


bool Printer::print(int pages) {
	this->printedCount = pages;

	if (this->availableCount >= this->printedCount) {
		this->availableCount -= this->printedCount;
		return true;
	}
	else {
		cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
		return false;
	}
}


void InkJetPrinter::printInkJet(int pages) {
	if (this->print(pages)) {
		this->availableInk -= pages;
		cout << "����Ʈ�Ͽ����ϴ�." << endl;
	}
}

void InkJetPrinter::show() {
	cout << this->getModel() << " ," << this->getManuf() << " ," << "���� ���� " << this->getCount() << "�� ,���� ��ũ " << this->getInk() << endl;
}


void LaserPrinter::printLaser(int pages) {
	if (this->print(pages)) {
		this->availableToner -= (pages - 1); //
		cout << "����Ʈ�Ͽ����ϴ�." << endl;
	}
}

void LaserPrinter::show() {
	cout << this->getModel() << " ," << this->getManuf() << " ," << "���� ���� " << this->getCount() << "�� ,������� " << this->getToner() << endl;
}