// 히스토그램을 표현하는 Histogram 클래스를 만들고 <<, ! 연산자를 작성해보자.
// Histogram 클래스는 영문자 알파벳만 다루며 대문자는 모두 소문자로 변환하여 처리한다.
// Histogram 클래스를 활용하는 코드 사례는 다음과 같다.
#include "OpenChallenge.h"

int main() {// falling in love with you. - by kit
	Histogram song("Wise men say, \nonly fools rush in But I can't help, \n");
	song << "falling" << " in love with you." << "- by "; // 히스토그램에 문자열 추가
	song << 'k' << 'i' << 't'; // 히스토그램에 문자 추가
	!song; // 히스토그램 그리기
}