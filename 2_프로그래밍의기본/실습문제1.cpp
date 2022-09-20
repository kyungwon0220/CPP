// cout과 << 연산자를 이용하여, 1에서 100까지 정수를 다음과 같이 한 줄에 10개씩 출력하라. 각 정수는 탭으로 분리하여 출력하라.
// 목적 : cout 활용, 화면 출력

#include <iostream>

using namespace std;

int main() {
	for (int i = 1; i <= 100; i++) {
		cout << i << "\t";

		if(i%10==0) cout << "\n";		
	}
}