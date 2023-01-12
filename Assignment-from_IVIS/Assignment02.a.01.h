#ifndef METHOD
#define METHOD

#include <iostream>

template <typename T> T Factorial(T x) {
	T A = 1;

	for(unsigned short i=1; i<=x; i++) A *= i;

	return A;
}

#else // 재귀 함수
template <typename T> T Factorial(T x) {
	if(x<=1) return 1;
	x *= Factorial(x-1);
}
#endif
