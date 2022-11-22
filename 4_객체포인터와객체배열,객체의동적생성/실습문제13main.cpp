// 영문자로 구성된 텍스트에 대해 각 알파벳에 해당하는 문자가 몇 개인지 출력하는 히스토그램 클래스 Histogram을 만들어보자.
// 대문자는 모두 소문자로 변환하여 처리한다.
// Histogram 클래스를 활용하는 사례와 실행 결과는 다음과 같다.


#include "실습문제13.h"

int main() {
	string inputS;

	getline(cin, inputS, '\n');

	Histogram elvisHisto(inputS);

	elvisHisto.print();
}