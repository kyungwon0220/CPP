#include "실습문제11.h"

Stack::Stack() { this->x = new int[3]; }
Stack::~Stack() { delete[] this->x; }

Stack& Stack::operator<<(int x) {
	this->x[this->index++] = x;
	return *this;
}

Stack& Stack::operator>>(int &x) {
	x = this->x[--index];
	return *this;
}

bool Stack::operator!() { if (this->index == 0) return true; else return false; }