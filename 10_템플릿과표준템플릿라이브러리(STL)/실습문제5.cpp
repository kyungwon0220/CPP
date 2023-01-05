// 다음 함수는 매개 변수로 주어진 두 개의 int 배열을 연결한 새로운 int 배열을 동적 할당 받아 리턴하라.
// int * concat(int a[], int sizea, int b[], int sizeb);
// concat가 int 배열뿐 아니라 다른 타입의 배열도 처리할 수 있도록 일반화하라.


template <typename T>
T* concat(T* a, int sizea, T* b, int sizeb) {
	T *c = new T[sizea+sizeb];
	
	for(unsigned short i=0; i<sizea; i++) c[i] = a[i];
	for(unsigned short i=0; i<sizeb; i++) c[i + sizea] = b[i];

	return c;
}


#include <iostream>

using namespace std;

int main() {
	int test1[5] = {11, 22, 33, 44, 55};
	int test2[5] = {66, 77, 88, 99, 1010};
	int *test3 = concat(test1, 5, test2, 5);
	
	for(unsigned short i=0; i<10; i++) cout << test3[i] << endl;


	// concat() 함수를 int로 구체화하는 경우
	cout << "두 개의 정수 배열을 합칩니다" << endl;

	int x[]={1,2,3};
	int y[]={6,7,8,9};
	int* p = concat(x, 3, y, 4);
	for(int i=0; i<7; i++) 
		cout << p[i] << ' ';

	cout << endl;
	delete [] p;


	// concat() 함수를 char로 구체화하는 경우
	cout << "두 개의 문자 배열을 합칩니다" << endl;

	char a[]={'L', 'o', 'v', 'e'};
	char b[]={'C', '+', '+'};
	char* q = concat(a, 4, b, 3);
	for(int i=0; i<7; i++) 
		cout << q[i] << ' ';

	cout << endl;
	delete [] q;
}