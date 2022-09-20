// <Enter> 키가 입력될 때까지 문자들을 읽고, 입력된 문자 'x'의 개수를 화면에 출력하라.
// 목적 : cin.getline()으로 한 줄의 문자열 읽기

#include <iostream>

using namespace std;

int main() {
	char s[100];
	unsigned long count = 0;

	cout << "문자들을 입력하라(100개 미만)." << endl;
	cin.getline(s, 100, '\n');

	for (int i = 0; i < strlen(s); i++) if (s[i] == 'x') count++;

	cout << "x의 개수는 " << count;
}