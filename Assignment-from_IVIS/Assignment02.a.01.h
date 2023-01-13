#include <iostream>

template <typename T> T Factorial(T x) {
	T a = 1;

	for (unsigned short i = 1;i <= x;i++) a *= i;

	return a;
}


// 재귀 함수
template <typename T> T Factorial_Recursion(T x) {
	if (x<=1) {
		return 1;
	} else {
		return x *= Factorial_Recursion(x-1);
	}
}