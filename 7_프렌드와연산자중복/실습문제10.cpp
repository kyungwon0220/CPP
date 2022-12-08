#include "실습문제10.h"

Statistics::Statistics() { this->n = new int[7]; }

Statistics::~Statistics() { delete[] this->n; }

bool Statistics::operator!() { if(this->size == 0) return true; else return false; }

Statistics& Statistics::operator<<(int x) {
	this->n[this->size++] = x;
	return *this;
}

void Statistics::operator~() {
	for (unsigned short i = 0; i<this->size; i++) cout << this->n[i] << ' ';
	cout << endl;
}

void Statistics::operator>>(int& avg) {
	int sum = 0;
	
	for (unsigned short i = 0; i < this->size; i++) sum += this->n[i];
	
	avg = sum / this->size;
}