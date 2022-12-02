#include "실습문제6.h"

int* ArrayUtility2::concat(int s1[], int s2[], int size) { // s1과 s2를 연결한 새로운 배열을 동적 생성하고 포인터 리턴
	int* p = new int[size * 2];

	for (unsigned short i = 0; i < size; i++) {
		p[i] = s1[i];
		p[size + i] = s2[i];
	}

	return p;
}


int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize) { // s1에서 s2에 있는 숫자를 모두 삭제한 새로운 배열을 동적 생성하여 리턴. 리턴하는 배열의 크기는 retSize에 전달. retSize가 0인 경우 NULL 리턴
	int* tmp = new int[size];

	retSize = size;

	for (unsigned short k = 0, i = 0; i < size; i++) {
		for (unsigned short j = 0; j <= size; j++) {
			if (j == size) {
				tmp[k++] = s1[i];
				break;
			}
			else if (s1[i] == s2[j]) {
				retSize--;
				break;
			}
		}
	}

	if (retSize == 0) return NULL;
	else return tmp;
}