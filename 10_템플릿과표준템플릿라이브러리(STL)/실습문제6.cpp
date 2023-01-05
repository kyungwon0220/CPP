// 다음 함수는 매개 변수로 주어진 int 배열 src에서 배열 minus에 들어있는 같은 정수를 모두 삭제한 새로운 int 배열을 동적으로 할당받아 리턴한다.
// retSize는 remove() 함수의 실행 결과를 리턴하는 배열의 크기를 전달받는다.
// int * remove(int src[], int sizeSrc, int minus[], int sizeMinus, int& retSize);
// 템플릿을 이용하여 remove를 일반화하라.


template <typename T>
T* remove(T* src, int sizeSrc, T* minus, int sizeMinus, int& retSize) {
	// retSize
	int count = 0;
	for(unsigned short i=0; i<sizeSrc; i++) {
		for(unsigned short j=0; j<sizeMinus; j++) {
			if(src[i] == minus[j]) { count++; break; }
		}
	}
	retSize = sizeSrc - count;

	T* a = new T[retSize];

	for(unsigned short k=0, i=0; i<sizeSrc; i++) {
		for(unsigned short j=0; j<sizeMinus; j++) {
			if(src[i] == minus[j]) break; // 같은 정수 발견시
			if(j == sizeMinus-1) a[k++] = src[i];
		}
	}

	return a;
}


#include <iostream>

using namespace std;

int main() {
	int test1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int test2[5] = {6, 7, 8, 9, 10};
	int retSize = 0;
	int *test3 = remove(test1, 10, test2, 5, retSize);

	for(unsigned short i=0; i<retSize; i++) cout << test3[i] << endl;
}