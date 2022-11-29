// 두 개의 Circle 객체를 교환하는 swap() 함수를 '참조에 의한 호출'이 되도록 작성하고 호출하는 프로그램을 작성하라.


#include "실습문제1.h"

int main() {
	Circle c1(10), c2(20);

	swap(c1, c2);

	cout << c1.getRadius() << endl << c2.getRadius() << endl;
}