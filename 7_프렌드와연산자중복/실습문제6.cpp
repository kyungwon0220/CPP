#include "실습문제6.h"

Matrix Matrix::operator+(Matrix m) {
	Matrix tmp;
	tmp.a = this->a + m.a;
	tmp.b = this->b + m.b;
	tmp.c = this->c + m.c;
	tmp.d = this->d + m.d;

	return tmp;
}

Matrix& Matrix::operator+=(Matrix m) {
	this->a += m.a;
	this->b += m.b;
	this->c += m.c;
	this->d += m.d;

	return *this;
}

bool Matrix::Matrix::operator==(Matrix m) {
	if (this->a == m.a && this->b == m.b && this->c == m.c && this->d == m.d) return true; else return false;
}

void Matrix::show() { cout << "Matrix = { " << this->a << " " << this->b << " " << this->c << " " << this->d << " }" << endl; }

//Matrix operator+(const Matrix m, const Matrix n) {
//	Matrix tmp;
//	tmp.a = m.a + n.a;
//	tmp.b = m.b + n.b;
//	tmp.c = m.c + n.c;
//	tmp.d = m.d + n.d;
//
//	return tmp;
//}
//
//Matrix operator+=(Matrix& m, const Matrix n) {
//	m.a += n.a;
//	m.b += n.b;
//	m.c += n.c;
//	m.d += n.d;
//
//	return m;
//}
//
//bool operator==(const Matrix& m, const Matrix& n) {
//	if (m.a == n.a && m.b == n.b && m.c == n.c && m.d == n.d) return true; else return false;
//}