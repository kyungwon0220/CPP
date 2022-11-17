#include <iostream>
#include <string>

using namespace std;


class Date {
private:
	unsigned short year;
	unsigned short m;
	unsigned short d;
public:
	Date(unsigned long y, unsigned long m, unsigned long d);
	Date(std::string s);

	unsigned short getYear();
	unsigned short getMonth();
	unsigned short getDay();
	void show();
};