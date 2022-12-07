#include <iostream>

using namespace std;

class Matrix {
	unsigned short a, b, c, d;
public:
	Matrix() : Matrix(0, 0, 0, 0) {} // 위임 생성자
	Matrix(unsigned short a, unsigned short b, unsigned short c, unsigned short d) { this->a = a; this->b = b; this->c = c; this->d = d; }

	void show();

	Matrix operator+(Matrix m); // friend Matrix operator+(const Matrix m, const Matrix n);
	Matrix& operator+=(Matrix m); // friend Matrix operator+=(Matrix& m, Matrix n);
	bool operator==(Matrix m); // friend bool operator==(const Matrix& m, const Matrix& n);
};