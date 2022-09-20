// 문자열을 두 개 입력받고 두 개의 문자열이 같은지 검사하는 프로그램을 작성하라. 만일 같으면 "같습니다", 아니면 "같지 않습니다"를 출력하라.
// 목적 : 공백 없이 입력된 문자열 읽기

#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	string s2;

	cout << "새 암호를 입력하세요>>";
	getline(cin, s);

	cout << "새 암호를 다시 한 번 입력하세요>>";
	getline(cin, s2);

	if (s.compare(s2) == 0) cout << "같습니다";
	else cout << "같지 않습니다";
}