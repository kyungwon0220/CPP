#include "�ǽ�����5.h"

void ArrayUtility::intToDouble(int source[], double dest[], int size) { // int[]�� double[]�� ��ȯ
	for (unsigned short i = 0; i < size; i++) dest[i] = source[i];
}
void ArrayUtility::doubleToInt(double source[], int dest[], int size) { // double[]�� int[]�� ��ȯ
	for (unsigned short i = 0; i < size; i++) dest[i] = (int)source[i];
}