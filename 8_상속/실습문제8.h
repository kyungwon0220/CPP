#include <iostream>

using namespace std;

class  Printer {
	string model; // �𵨸�
	string manufacturer; // ������
	int printedCount; // �μ� �ż�
	unsigned short availableCount; // �μ� ���� �ܷ�
public:
	Printer(string model, string manufacturer, unsigned short availableCount) { this->model = model; this->manufacturer = manufacturer; this->availableCount = availableCount; } // ������

	bool print(int pages);

	string getModel() { return this->model; }
	string getManuf() { return this->manufacturer; }
	unsigned short getCount() { return this->availableCount; }
};

class InkJetPrinter : private Printer {
	unsigned short availableInk; // ��ũ �ܷ�
public:
	InkJetPrinter(string model, string manufacturer, unsigned short availablecount, unsigned short availableInk) : Printer(model, manufacturer, availablecount) { this->availableInk = availableInk; } // ������

	unsigned short getInk() { return this->availableInk; }

	void printInkJet(int pages);

	void show();
};

class LaserPrinter : private Printer {
	unsigned short availableToner; // ��� �ܷ�
public:
	LaserPrinter(string model, string manufacturer, unsigned short availablecount, unsigned short availableToner) : Printer(model, manufacturer, availablecount) { this->availableToner = availableToner; } // ������

	unsigned short getToner() { return this->availableToner; }

	void printLaser(int pages);
	void show();
};