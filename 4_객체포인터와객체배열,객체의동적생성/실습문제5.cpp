// string 클래스를 이용하여 사용자가 입력한 영문 한 줄을 입력받고 글자 하나만 랜덤하게 수정하여 출력하는 프로그램을 작성하라.


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


int main() {
	string s;
	char text; // 랜덤 글자
	int n, rindex;


	cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다)" << endl;

	while(1) {
		cout << ">>";

		getline(cin, s, '\n');

		if (s.compare("exit") == 0) break; // 종료 조건

		srand((unsigned)time(0)); // 시작할 때마다, 다른 랜덤수를 발생시키기 위한 seed 설정
		n = rand(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수 발생

		if (n % 2 == 0) {
			text = (int)(n % (int)26) + (int)65; // 랜덤 대문자
		}
		else {
			text = (int)(n % (int)26) + (int)97; // 랜덤 소문자
		}
		
		rindex = n % s.length(); // 랜덤 인덱스

		while(s[rindex] == ' ') { rindex = n % s.length(); } // 랜덤 인덱스 위치의 문자가 공백일시, 다른 랜덤 인덱스로

		s[rindex] = (char)text;

		cout << s << endl;
	}
}