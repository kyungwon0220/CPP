#include <iostream>

using namespace std;

class Matrix {
	unsigned short a, b, c, d;
public:
	Matrix() : Matrix(0, 0, 0, 0) {} // 위임 생성자
	Matrix(unsigned short a, unsigned short b, unsigned short c, unsigned short d) { this->a = a; this->b = b; this->c = c; this->d = d; }

	void show();

	friend void operator>>(Matrix& m, int* x); //void operator>>(int *x);
	friend void operator<<(Matrix& m, const int* x); //void operator<<(const int *x);
};