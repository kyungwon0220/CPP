#include "실습문제2.h"


Date::Date(unsigned long y, unsigned long m, unsigned long d) {
	this->year = y;
	this->m = m;
	this->d = d;
}


Date::Date(string s) {
	unsigned short check = 0;
	unsigned short findex = 0;
	string part;

	for(unsigned short i=0; i<3; i++) {
		findex = s.find('/',check); // findex == ' check ' 인덱스부터, '/' 문자열이 검색된 인덱스
		
		part = s.substr(check, findex - check);

		if (i == 0) // 첫 번째로, '/' 문자열이 검색되었을시
			this->year = stoi(part);
		else if (i == 1) // 두 번째, '/' 문자열이 검색되었을시
			this->m = stoi(part);
		else if (i == 2) // '/' 문자열이 검색되지 않는, 세 번째 find
			this->d = stoi(s.substr(check, 2));

		check = findex + 1;
	}
}


void Date::show() { cout << this->year << "년" << this->m << "월" << this->d << "일" << endl; }
unsigned short Date::getYear() { return this->year; }
unsigned short Date::getMonth() { return this->m; }
unsigned short Date::getDay() { return this->d; }