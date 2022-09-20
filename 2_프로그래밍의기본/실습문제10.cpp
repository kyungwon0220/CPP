// 문자열을 하나 입력받고 문자열의 부분 문자열을 다음과 같이 출력하는 프로그램을 작성하라. 예시는 다음과 같다.
// 목적 : 문자열 읽기. 문자열 다루기

#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;

	getline(cin, s);

	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j <= i; j++) cout << s[j];

		cout << '\n';
	}
}