#include "실습문제7.h"

void Matrix::show() { cout << "Matrix = { " << this->a << " " << this->b << " " << this->c << " " << this->d << " }" << endl; }

//void Matrix::operator>>(int* x) {
//	x[0] = this->a;
//	x[1] = this->b;
//	x[2] = this->c;
//	x[3] = this->d;
//}
//
//void Matrix::operator<<(const int* x) {
//	this->a = x[0];
//	this->b = x[1];
//	this->c = x[2];
//	this->d = x[3];
//}

void operator>>(Matrix& m, int* x) {
	x[0] = m.a;
	x[1] = m.b;
	x[2] = m.c;
	x[3] = m.d;
}

void operator<<(Matrix& m, const int* x) {
	m.a = x[0];
	m.b = x[1];
	m.c = x[2];
	m.d = x[3];
}