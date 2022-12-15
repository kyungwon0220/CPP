#include "실습문제8.h"


bool Printer::print(int pages) {
	this->printedCount = pages;

	if (this->availableCount >= this->printedCount) {
		this->availableCount -= this->printedCount;
		return true;
	}
	else {
		cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
		return false;
	}
}


void InkJetPrinter::printInkJet(int pages) {
	if (this->print(pages)) {
		this->availableInk -= pages;
		cout << "프린트하였습니다." << endl;
	}
}

void InkJetPrinter::show() {
	cout << this->getModel() << " ," << this->getManuf() << " ," << "남은 종이 " << this->getCount() << "장 ,남은 잉크 " << this->getInk() << endl;
}


void LaserPrinter::printLaser(int pages) {
	if (this->print(pages)) {
		this->availableToner -= (pages - 1); //
		cout << "프린트하였습니다." << endl;
	}
}

void LaserPrinter::show() {
	cout << this->getModel() << " ," << this->getManuf() << " ," << "남은 종이 " << this->getCount() << "장 ,남은토너 " << this->getToner() << endl;
}