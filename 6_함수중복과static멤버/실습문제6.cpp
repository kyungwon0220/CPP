#include "�ǽ�����6.h"

int* ArrayUtility2::concat(int s1[], int s2[], int size) { // s1�� s2�� ������ ���ο� �迭�� ���� �����ϰ� ������ ����
	int* p = new int[size * 2];

	for (unsigned short i = 0; i < size; i++) {
		p[i] = s1[i];
		p[size + i] = s2[i];
	}

	return p;
}


int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize) { // s1���� s2�� �ִ� ���ڸ� ��� ������ ���ο� �迭�� ���� �����Ͽ� ����. �����ϴ� �迭�� ũ��� retSize�� ����. retSize�� 0�� ��� NULL ����
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