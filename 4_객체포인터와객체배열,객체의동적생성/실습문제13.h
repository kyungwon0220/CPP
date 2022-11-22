#include <iostream>
#include <string>

using namespace std;

class Histogram {
private:
	int lenSize = 0;
	unsigned short* ABC = new unsigned short[26]{ 0, };
public:
	Histogram(string s); // 持失切
	~Histogram() {} // 社瑚切

	void print();	
};