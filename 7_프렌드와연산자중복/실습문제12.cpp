#include "실습문제12.h"

SortedArray::SortedArray() { this->p = NULL; this->size = 0; } // 기본 생성자
SortedArray::SortedArray(int p[], int size) { this->size = size; this->p = new int[size]; for (unsigned short i = 0; i < size; i++) this->p[i] = p[i]; } // 생성자
SortedArray::SortedArray(SortedArray& src) { this->size = src.size; this->p = new int[src.size]; for (unsigned short i = 0; i < src.size; i++) this->p[i] = src.p[i]; } // 복사 생성자
SortedArray::~SortedArray() { if(this->p) delete[] this->p; } // 소멸자

void SortedArray::sort() {
	int tmp;

	for (unsigned short i = 0; i < this->size-1; i++) {
		for (unsigned short j = i+1; j < this->size; j++) {
			if (this->p[i] > this->p[j]) {
				tmp = this->p[i];
				this->p[i] = this->p[j];
				this->p[j] = tmp;
			}
		}		
	}
}
void SortedArray::show() {
	this->sort();

	cout << "배열 출력 : ";

	for (unsigned short i = 0; i < this->size; i++) cout << this->p[i] << ' ';

	cout << endl;
}

SortedArray SortedArray::operator + (SortedArray& op2) {
	SortedArray tmp;

	tmp.size = this->size + op2.size;
	tmp.p = new int[tmp.size];

	for (unsigned short i = 0; i < this->size; i++) tmp.p[i] = this->p[i];
	for (unsigned short i = 0; i < op2.size; i++) tmp.p[this->size + i] = op2.p[i];

	return tmp;
}

SortedArray& SortedArray::operator = (const SortedArray& op2) {
	delete[] this->p;

	this->size = op2.size;
	this->p = new int[op2.size];

	for (unsigned short i = 0; i < op2.size; i++) this->p[i] = op2.p[i];

	return *this;
}