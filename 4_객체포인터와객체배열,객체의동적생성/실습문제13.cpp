#include "�ǽ�����13.h"

Histogram::Histogram(string s) { // ������
	for (unsigned short i = 0; i < s.length(); i++) {
		if (s.at(i) >= 'A' && s.at(i) <= 'Z') {
			this->ABC[s.at(i) % 65]++; // �빮�� ī��Ʈ
			this->lenSize++;
		}
		else if (s.at(i) >= 'a' && s.at(i) <= 'z') {
			this->ABC[s.at(i) % 97]++; // �ҹ��� ī��Ʈ
			this->lenSize++;
		}
	}
}


void Histogram::print() {
	cout << endl << "�� ���ĺ� �� " << this->lenSize << endl << endl;

	for (unsigned short i = 0; i < 26; i++) {
		cout << (char)(i + 97) << " (" << this->ABC[i]  << ")\t: ";
		
		for (unsigned short j = 0; j < this->ABC[i]; j++) cout << "*";

		cout << endl;
	}
	
}