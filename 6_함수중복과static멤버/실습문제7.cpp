#include "실습문제7.h"

int Random::nextInt(int min = 0, int max = 32767) { // min과 max 사이의 랜덤 정수 리턴)
	int n;

	do {
		n = rand();
		
	} while ((n % max) > max);

	return n%max + min;
}

char Random::nextAlphabet() { // 랜덤 알파벳 문자 리턴
	char n;

	do {
		n = Random::nextInt() % 'z';
	} while (!(n >= 'A' && n <= 'Z') || (n <= 'a' && n >= 'z'));

	return (char)n;
}

double Random::nextDouble() { // 0보다 크거나 같고 1보다 적은 랜덤 실수 리턴
	double n;

	n = rand();

	return n * 0.000001;
}