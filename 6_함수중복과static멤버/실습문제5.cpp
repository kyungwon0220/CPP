#include "실습문제5.h"

void ArrayUtility::intToDouble(int source[], double dest[], int size) { // int[]을 double[]로 변환
	for (unsigned short i = 0; i < size; i++) dest[i] = source[i];
}
void ArrayUtility::doubleToInt(double source[], int dest[], int size) { // double[]을 int[]로 변환
	for (unsigned short i = 0; i < size; i++) dest[i] = (int)source[i];
}