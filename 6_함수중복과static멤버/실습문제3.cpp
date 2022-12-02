// 함수 big()을 호출하는 경우는 다음과 같다.
// (1) big() 함수를 2개 중복하여 작성하고 프로그램을 완성하라.
// (2) 디폴트 매개 변수를 가진 하나의 함수로 big()을 작성하고 프로그램을 완성하라.

#include <iostream>

using namespace std;

int big(int x, int y, int max = 100) {
	int bigg;
	if (x > y) bigg = x;
	else if (x < y) bigg = y;

	if (max > bigg) return bigg;
	else return max;
}
int main() {
	int x = big(3, 5); // 3과 5 중 큰 값 5는 최대값 100보다 작으므로, 5 리턴
	int y = big(300, 60); // 300과 60 중 큰 값 300이 최대값 100보다 크므로, 100 리턴
	int z = big(30, 60, 50); // 30과 60 중 큰 값 60이 최대값 50보다 크므로, 50 리턴
	cout << x << ' ' << y << ' ' << z << endl;
}