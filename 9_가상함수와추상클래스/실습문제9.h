#include <iostream>

using namespace std;

class Printer {
	string model; // �𵨸�
	string manufacturer; // ������

	virtual void print(int pages) = 0;
	virtual void show() = 0;
protected:
	//unsigned short printedCount; // �μ� �ż�
	unsigned short availableCount; // �μ� ���� �ܷ�

	Printer(string name, string manufacturer, unsigned short availableCount) { this->model = name; this->manufacturer = manufacturer; this->availableCount = availableCount; } // ������
	virtual ~Printer() {} // ���� �Ҹ���

	string getName() { return this->model; }
	string getManufacturer() { return this->manufacturer; }
};


class InkJetPrinter : private Printer {
	unsigned short availableInk;
public:
	InkJetPrinter(string name, string manufacturer, unsigned short availableCount, unsigned short availableInk) : Printer(name, manufacturer, availableCount) { this->availableInk = availableInk; } // ������
	virtual ~InkJetPrinter() {} // ���� �Ҹ���

	virtual void print(int pages);
	virtual void show();
};


class LaserPrinter : private Printer {
	unsigned short availableToner;
public:
	LaserPrinter(string name, string manufacturer, unsigned short availableCount, unsigned short availableToner) : Printer(name, manufacturer, availableCount) { this->availableToner = availableToner; } // ������
	virtual ~LaserPrinter() {} // ���� �Ҹ���

	virtual void print(int pages);
	virtual void show();
};