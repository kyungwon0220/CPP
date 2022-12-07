#include <iostream>
#include <string>

using namespace std;

class Histogram {
	string str;
	unsigned short alpa[26] = { 0, };
	unsigned short count = 0;
public:
	Histogram(string str); // 생성자

	Histogram& operator<< (string s);
	Histogram& operator<<(char c);
	void operator!(); // ! 연산자 함수 선언
};