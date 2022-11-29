// ������ ���� �۵��ϵ��� combine() �Լ��� �ۼ��϶�.

#include <iostream>

using namespace std;

void combine(const string& text1, const string& text2, string& text3) { text3 = text1 + " " + text2; }

int main() {
	string text1("I love you"), text2("very much");
	string text3; // ��� �ִ� ���ڿ�
	combine(text1, text2, text3); // text1�� " ", �׸��� text2�� ���ٿ� text3 �����
	cout << text3; // "I love you very much" ���
}