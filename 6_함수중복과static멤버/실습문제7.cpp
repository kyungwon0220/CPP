#include "�ǽ�����7.h"

int Random::nextInt(int min = 0, int max = 32767) { // min�� max ������ ���� ���� ����)
	int n;

	do {
		n = rand();
		
	} while ((n % max) > max);

	return n%max + min;
}

char Random::nextAlphabet() { // ���� ���ĺ� ���� ����
	char n;

	do {
		n = Random::nextInt() % 'z';
	} while (!(n >= 'A' && n <= 'Z') || (n <= 'a' && n >= 'z'));

	return (char)n;
}

double Random::nextDouble() { // 0���� ũ�ų� ���� 1���� ���� ���� �Ǽ� ����
	double n;

	n = rand();

	return n * 0.000001;
}