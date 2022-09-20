// 다음 C 프로그램을 C++ 프로그램으로 수정하여 실행하라.
// 비주얼 스튜디오에서 scanf로 인한 오류를 막으려면 첫줄에 다음 문 삽입
// #define _CRT_SECURE_NO_WARNINGS
// 목적 : C++ 프로그래밍에 대한 전반적인 이해

#include <iostream>

using namespace std;

int sum(int a, int b) {
	int sum = 0;

	for (int i = a; i <= b; i++) sum += i;

	return sum;
}

int main() {
	unsigned long n;
	
	cout << "끝 수를 입력하세요>>";
	cin >> n;	

	cout << "1에서 " << n << "까지의 합은 " << sum(1, n) << "입니다.";
}