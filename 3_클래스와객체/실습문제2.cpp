#include "�ǽ�����2.h"


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
		findex = s.find('/',check); // findex == ' check ' �ε�������, '/' ���ڿ��� �˻��� �ε���
		
		part = s.substr(check, findex - check);

		if (i == 0) // ù ��°��, '/' ���ڿ��� �˻��Ǿ�����
			this->year = stoi(part);
		else if (i == 1) // �� ��°, '/' ���ڿ��� �˻��Ǿ�����
			this->m = stoi(part);
		else if (i == 2) // '/' ���ڿ��� �˻����� �ʴ�, �� ��° find
			this->d = stoi(s.substr(check, 2));

		check = findex + 1;
	}
}


void Date::show() { cout << this->year << "��" << this->m << "��" << this->d << "��" << endl; }
unsigned short Date::getYear() { return this->year; }
unsigned short Date::getMonth() { return this->m; }
unsigned short Date::getDay() { return this->d; }