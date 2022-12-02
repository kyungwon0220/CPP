// add() 함수를 호출하는 main() 함수는 다음과 같다.
// (1) add() 함수를 중복 작성하고 프로그램을 완성하라.
// (2) 디폴트 매개 변수를 가진 하나의 add() 함수를 작성하고 프로그램을 완성하라.

#include <iostream>

using namespace std;

int add(int *p1, unsigned short size, int *p2 = NULL) { // NULL 대신 nullptr로 하는 것이 바람직함
	int sum = 0;

	if (p2) for (unsigned short i = 0; i < size; i++) sum += p2[i] + p1[i];
	else for (unsigned short i = 0; i < size; i++) sum += p1[i];
	
	return sum;
}
int main() {
	int a[] = { 1,2,3,4,5 };
	int b[] = { 6,7,8,9,10 };
	int c = add(a, 5); // 배열 a의 정수를 모두 더한 값 리턴
	int d = add(a, 5, b); // 배열 a와 b의 정수를 모두 더한 값 리턴
	cout << c << endl; // 15 출력
	cout << d << endl; // 55  출력
}