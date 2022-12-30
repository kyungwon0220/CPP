// Create application that calculates factorial of a number using recursion and without it (make 2 separate functions).
// 재귀를 사용하거나 사용하지 않고 숫자의 계승을 계산하는 응용 프로그램을 만듭니다(별도의 함수 2개 만들기).


#include <iostream>

using namespace std;


// template <typename T> T Factorial(T x) {
// 	T A = 1;

// 	for(unsigned short i=1; i<=x; i++) A *= i;

// 	return A;
// }


// 재귀 함수
template <typename T> T Factorial(T x) {
	if(x<=1) return 1;
	x *= Factorial(x-1);
}

int main() {
	int x;

	cout << "Input number: ";
	cin >> x;

	cout << "Factorial of " << x << " is " << Factorial(x);
}