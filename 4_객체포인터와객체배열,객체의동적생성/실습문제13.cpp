#include "실습문제13.h"

Histogram::Histogram(string s) { // 생성자
	for (unsigned short i = 0; i < s.length(); i++) {
		if (s.at(i) >= 'A' && s.at(i) <= 'Z') {
			this->ABC[s.at(i) % 65]++; // 대문자 카운트
			this->lenSize++;
		}
		else if (s.at(i) >= 'a' && s.at(i) <= 'z') {
			this->ABC[s.at(i) % 97]++; // 소문자 카운트
			this->lenSize++;
		}
	}
}


void Histogram::print() {
	cout << endl << "총 알파벳 수 " << this->lenSize << endl << endl;

	for (unsigned short i = 0; i < 26; i++) {
		cout << (char)(i + 97) << " (" << this->ABC[i]  << ")\t: ";
		
		for (unsigned short j = 0; j < this->ABC[i]; j++) cout << "*";

		cout << endl;
	}
	
}