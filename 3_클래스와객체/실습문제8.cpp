// int 타입의 정수를 객체화한 Integer 클래스를 작성하라. Integer의 모든 멤버 함
// 수를 자동 인라인으로 작성하라. Integer 클래스를 활용하는 코드는 다음과 같다.
// 문제2의 힌트와 동일하게 <string> 헤더 파일의 stoi() 함수를 이용하면 편하다.
/*
* 30 50 300 1
*/
#include <iostream>
#include "실습문제8.h"

using namespace std;

int main() {
	Integer n(30);
	cout << n.get() << ' '; // 30 출력
	n.set(50);
	cout << n.get() << ' '; // 50 출력

	Integer m("300");
	cout << m.get() << ' '; // 300 출력
	cout << m.isEven(); // true(정수로 1) 출력
}