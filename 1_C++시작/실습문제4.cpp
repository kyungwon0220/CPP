// 다음과 같이 출력하는 C++ 프로그램을 비주얼 스튜디오로 작성하라.
#include <iostream>

using namespace std;

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j <= i; j++) cout << "*";

		cout << "\n";
	}
}