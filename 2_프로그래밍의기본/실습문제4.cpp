// 소수점을 가지는 5개의 실수를 입력 받아 제일 큰 수를 화면에 출력하라.
// 목적 : cin 활용, 키보드로부터 정수 읽기

#include <iostream>

using namespace std;

int main() {
	float f[5];
	float max;

	cout << "5 개의 실수를 입력하라>>";
	
	cin >> f[0];
	max = f[0];

	for (int i = 1; i < 5; i++) {
		cin >> f[i];
		if (max < f[i]) max = f[i];
	}

	cout << "제일 큰 수 = " << max;
}