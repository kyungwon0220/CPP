#include <iostream>
#include <string>

using namespace std;

class Histogram {
	string str;
	unsigned short alpa[26] = { 0, };
	unsigned short count = 0;
public:
	Histogram(string str); // ������

	Histogram& operator<< (string s);
	Histogram& operator<<(char c);
	void operator!(); // ! ������ �Լ� ����
};