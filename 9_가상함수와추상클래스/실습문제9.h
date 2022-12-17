#include <iostream>

using namespace std;

class Printer {
	string model; // 모델명
	string manufacturer; // 제조사

	virtual void print(int pages) = 0;
	virtual void show() = 0;
protected:
	//unsigned short printedCount; // 인쇄 매수
	unsigned short availableCount; // 인쇄 종이 잔량

	Printer(string name, string manufacturer, unsigned short availableCount) { this->model = name; this->manufacturer = manufacturer; this->availableCount = availableCount; } // 생성자
	virtual ~Printer() {} // 가상 소멸자

	string getName() { return this->model; }
	string getManufacturer() { return this->manufacturer; }
};


class InkJetPrinter : private Printer {
	unsigned short availableInk;
public:
	InkJetPrinter(string name, string manufacturer, unsigned short availableCount, unsigned short availableInk) : Printer(name, manufacturer, availableCount) { this->availableInk = availableInk; } // 생성자
	virtual ~InkJetPrinter() {} // 가상 소멸자

	virtual void print(int pages);
	virtual void show();
};


class LaserPrinter : private Printer {
	unsigned short availableToner;
public:
	LaserPrinter(string name, string manufacturer, unsigned short availableCount, unsigned short availableToner) : Printer(name, manufacturer, availableCount) { this->availableToner = availableToner; } // 생성자
	virtual ~LaserPrinter() {} // 가상 소멸자

	virtual void print(int pages);
	virtual void show();
};