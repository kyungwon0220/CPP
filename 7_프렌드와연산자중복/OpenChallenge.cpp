#include "OpenChallenge.h"

Histogram::Histogram(string str) { this->str = str; }

Histogram& Histogram::operator<<(string s) { this->str += s; return *this; }
Histogram& Histogram::operator<<(char c) { this->str += c; return *this; }
void Histogram::operator!() {

	cout << this->str << endl << endl;

	for (unsigned short i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			this->alpa[tolower(str[i]) - 'a']++;
			this->count++;
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			this->alpa[str[i] - 'a']++;
			this->count++;
		}
	}


	cout << "ÃÑ ¾ËÆÄºª ¼ö " << this->count << endl;

	for (unsigned short i = 0; i < 26; i++) {
		cout << (char)(i + 'a') << ":";
		
		for (unsigned short j = 0; j < this->alpa[i]; j++) cout << "*";
		
		cout << endl;
	}
}