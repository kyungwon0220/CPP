#include <iostream>
#include <string>

using namespace std;

class Histogram {
private:
	int lenSize = 0;
	unsigned short* ABC = new unsigned short[26]{ 0, };
public:
	Histogram(string s); // ������
	~Histogram() {} // �Ҹ���

	void print();	
};