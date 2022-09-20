// 1에서 10까지 더하여 결과를 다음과 같이 화면에 출력하는 C++ 프로그램을 비주얼 스튜디오로 작성하라.

#include <iostream>

using namespace std;

int main() {
	int sum = 0;
	for (int i = 1; i <= 10; i++)
		sum += i;
	cout << "1에서 10까지 더한 결과는 ";
	cout << sum << "입니다\n";
	return 0;
}