// string 클래스를 이용하여 사용자가 입력한 영문 한 줄을 문자열로 입력받고 거꾸로 출력하는 프로그램을 작성하라.


#include <iostream>
#include <string>

using namespace std;


int main() {
	string s;


	cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다)" << endl;

	while (1) {
		cout << ">>";
		getline(cin, s, '\n');

		if (s.compare("exit") == 0) break; // 종료 조건

		for(short i=s.length() - 1; i>=0; i--) cout << s[i];
		cout << endl;
	}
}