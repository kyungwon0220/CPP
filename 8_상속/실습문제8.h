#include <iostream>

using namespace std;

class  Printer {
	string model; // ¸ðµ¨¸í
	string manufacturer; // Á¦Á¶»ç
	int printedCount; // ÀÎ¼â ¸Å¼ö
	unsigned short availableCount; // ÀÎ¼â Á¾ÀÌ ÀÜ·®
public:
	Printer(string model, string manufacturer, unsigned short availableCount) { this->model = model; this->manufacturer = manufacturer; this->availableCount = availableCount; } // »ý¼ºÀÚ

	bool print(int pages);

	string getModel() { return this->model; }
	string getManuf() { return this->manufacturer; }
	unsigned short getCount() { return this->availableCount; }
};

class InkJetPrinter : private Printer {
	unsigned short availableInk; // À×Å© ÀÜ·®
public:
	InkJetPrinter(string model, string manufacturer, unsigned short availablecount, unsigned short availableInk) : Printer(model, manufacturer, availablecount) { this->availableInk = availableInk; } // »ý¼ºÀÚ

	unsigned short getInk() { return this->availableInk; }

	void printInkJet(int pages);

	void show();
};

class LaserPrinter : private Printer {
	unsigned short availableToner; // Åä³Ê ÀÜ·®
public:
	LaserPrinter(string model, string manufacturer, unsigned short availablecount, unsigned short availableToner) : Printer(model, manufacturer, availablecount) { this->availableToner = availableToner; } // »ý¼ºÀÚ

	unsigned short getToner() { return this->availableToner; }

	void printLaser(int pages);
	void show();
};