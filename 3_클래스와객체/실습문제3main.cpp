// 은행에서 사용하는 프로그램을 작성하기 위해, 은행 계좌 하나를 표현하는 클래스
// Account가 필요하다. 계좌 정보는 계좌의 주인, 계좌 번호, 잔액을 나타내는 3 멤버
// 변수로 이루어진다. main() 함수의 실행 결과가 다음과 같도록 Account 클래스를 작
// 성하라.
// Account는 name, id, balance(잔액)의 3 멤버 변수와 생성자, getOwner(), deposit(),
// withdraw(), inquiry()의 3 멤버 함수를 가지는 클래스로 만들면 된다.

/*
* Kiate의 잔액은 55000
* Kitae의 잔액은 35000
*/
#include <iostream>
#include "실습문제3.h"

using namespace std;

int main() {
	Account a("kitae", 1, 5000); // id 1번, 잔액 5000원, 이름이 kitae인 계좌 생성
	a.deposit(50000); // 50000원 저금
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
	unsigned long money = a.withdraw(20000); // 20000원 출금. withdraw()는 출금한 실제 금액 리턴
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
}