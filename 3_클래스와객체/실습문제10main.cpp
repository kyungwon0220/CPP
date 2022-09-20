// 다수의 클래스를 선언하고 활용하는 간단한 문제이다. 더하기(+), 빼기(-), 곱하기
// (*), 나누기(/)를 수행하는 4개의 클래스 Add, Sub, Mul, Div를 만들고자 한다. 이들
// 은 모두 공통으로 다음 멤버를 가진다.
// - int 타입 변수 a, b : 피연산자
// - void setValue(int x, int y) 함수 : 매개 변수 x, y를 멤버 a, b에 복사
// - int calculate() 함수 : 연산을 실행하고 결과 리턴
// main() 함수는 Add, Sub, Mul, Div 클래스 타입의 객체 a, s, m, d를 생성하고, 아래
// 와 같이 키보드로부터 두 개의 정수와 연산자를 입력받고, a, s, m, d 객체 중에서 연
// 산을 처리할 객체의 setValue() 함수를 호출한 후, calculate()를 호출하여 결과를
// 화면에 출력한다. 프로그램은 무한 루프를 돈다.
// 클래스 선언부와 구현부를 분리하고, 모든 코드를 실습문제10.cpp 파일에 작성하라.
// 클래스의 선언부와 구현부를 헤더 파일과 cpp 파일로 나누어 프로그램을 작성하라.
/*
* 두 정수와 연산자를 입력하세요>> 3 4 *
* 12
* 두 정수와 연산자를 입력하세요>> 5 2 /
* 2
* 두 정수와 연산자를 입력하세요>> 8 2 -
* 6
*/
#include <iostream>
#include "실습문제10.h"

using namespace std;

int main() {
	int x, y;
	char value;

	while (1) {
		Add a;
		Sub s;
		Mul m;
		Div d;

		cout << "두 정수와 연산자를 입력하세요>>";
		cin >> x >> y >> value;

		switch (value) {
		case '+':
			a.setValue(x, y);
			cout << a.calculate() << endl;
			break;
		case '-':
			s.setValue(x, y);
			cout << s.calculate() << endl;
			break;
		case '*':
			m.setValue(x, y);
			cout << m.calculate() << endl;
			break;
		case '/':
			d.setValue(x, y);
			cout << d.calculate() << endl;
			break;
		} // switch end
	} // while end
} // main end