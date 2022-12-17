#include "실습문제9.h"

void InkJetPrinter::print(int pages) {
	if (pages > this->availableCount) cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
	else {
		if (availableInk < pages) cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;
		else {
			this->availableCount -= pages;
			availableInk -= pages;
			cout << "프린트하였습니다." << endl;
		}
	}
}

void InkJetPrinter::show() { cout << this->getName() << " ," << this->getManufacturer() << " ," << this->availableCount << "장 ,남은 잉크 " << this->availableInk << endl; }


void LaserPrinter::print(int pages) {
	if (pages > this->availableCount) cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
	else {
		if (availableToner < 1) cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
		else {
			this->availableCount -= pages;
			availableToner -= 1;
			cout << "프린트하였습니다." << endl;
		}			
	}
}

void LaserPrinter::show() { cout << this->getName() << " ," << this->getManufacturer() << " ," << this->availableCount << "장 ,남은토너 " << this->availableToner << endl; }
