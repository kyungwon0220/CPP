// 날짜를 다루는 Date 클래스를 작성하고자 한다.
// Date를 이용하는 main()과 실행 결과는 다음과 같다.
// 클래스 Date를 작성하여 아래 프로그램에 추가하라.


#include "실습문제2.h"

int main() {
	Date birth(2014, 3, 20); // 2014년 3월 20일
	Date independenceDay("1945/8/15/"); // 1945년 8월 15일

	independenceDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;
}