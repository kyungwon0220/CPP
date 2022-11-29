// 다음과 같이 작동하도록 combine() 함수를 작성하라.

#include <iostream>

using namespace std;

void combine(const string& text1, const string& text2, string& text3) { text3 = text1 + " " + text2; }

int main() {
	string text1("I love you"), text2("very much");
	string text3; // 비어 있는 문자열
	combine(text1, text2, text3); // text1과 " ", 그리고 text2를 덧붙여 text3 만들기
	cout << text3; // "I love you very much" 출력
}