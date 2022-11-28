// 아래 <표5-1>을 참고하여 영문 텍스트, 숫자, 몇 개의 특수 문자로 구성되는 텍스트를 모스 부호로 변환하는 프로그램을 작성하라.
// 모스 부호는 전보를 쳐서 통신하는 시절에 사용된 유명한 코딩 시스템이다.
// 각 모스 코드들을 하나의 빈칸으로 분리되고, 영문 한 워드가 모스 워드로 변환되면 워드들은 3개의 빈칸으로 분리된다.
// 실행 예는 다음과 같다. 영문 텍스트를 입력받아 모스 부호로 변환하여 출력하고, 변환이 잘 되었는지 확인하기 위해 다시 모스 부호를 영문 텍스트로 변환하여 원문을 출력한 사례이다.


#include "OpenChallenge.h"

int main() {
	string text, morse;
	Morse m;

	cout << "아래에 영문 텍스트를 입력하세요. 모스 부호로 바꿉니다." << endl;

	getline(cin, text, '\n');	

	m.text2Morse(text, morse);

	cout << morse << endl << endl;

	cout << "모스 부호를 다시 영문 텍스트로 바꿉니다." << endl;

	if (m.morse2Text(morse, text)) cout << text << endl;
	else cout << "모스 부호가 아닙니다." << endl;
}