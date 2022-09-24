// 다음과 같이 "yes"가 입력될 때까지 종료하지 않는 프로그램을 작성하라. 사용자로부터의 입력은 cin.getline() 함수를 사용하라.
// 목적 : 공백을 포함하는 문자열 읽기

#include <iostream>
using namespace std;

int main() {
	char sayY[100];
	
	do {
		cin.getline(sayY, 100);
	} while (strcmp(sayY, "yes") != 0);
}