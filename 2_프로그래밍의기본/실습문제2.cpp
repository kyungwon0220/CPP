// cout과 << 연산자를 이용하여 다음과 같이 구구단을 출력하는 프로글매을 작성하라.
// 목적 : cout 활용, 화면 출력

#include <iostream>

using namespace std;

int main() {
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) cout << j << "x" << i << "=" << i * j << "\t";

		cout << "\n";
	}
}