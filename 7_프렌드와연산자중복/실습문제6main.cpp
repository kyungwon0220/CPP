// 2차원 행렬을 추상화한 Matrix 클래스를 작성하고, show() 멤버 함수와 다음 연산이 간으하도록 연산자를 모두 구현하라.
// (1) 연산자 함수를 Matrix의 멤버 함수로 구현하라.
// (2) 연산자 함수를 Matrix의 프렌드 함수로 구현하라.

#include "실습문제6.h"

int main() {
	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
	c = a + b;
	a += b;
	a.show(); b.show(); c.show();
	if (a == c) cout << "a and c are the same" << endl;
}