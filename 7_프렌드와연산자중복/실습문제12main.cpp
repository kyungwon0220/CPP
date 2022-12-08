// 정수 배열을 항상 증가 순으로 유지하는 SortedArray 클래스를 작성하려고 한다.
// 아래의 main() 함수가 작동할 만큼만 SortedArray 클래스를 작성하고 +와 = 연산자도 작성하라.

#include "실습문제12.h"

int main() {
	int n[] = { 2, 20, 6 };
	int m[] = { 10, 7, 8, 30 };
	SortedArray a(n, 3), b(m, 4), c;

	c = a + b; // +, = 연산자 작성 필요
	// + 연산자가 SortedArray 객체를 리턴하므로 복사 생성자 필요

	a.show();
	b.show();
	c.show();
}