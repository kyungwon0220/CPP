// 동일한 크기로 배열을 변환하는 다음 2개의 static 멤버 함수를 가진 ArrayUtility 클래스를 만들어라.
// ArrayUtility를 활용하는 main()은 다음과 같다.

#include "실습문제5.h"


int main() {
	int x[] = { 1,2,3,4,5 };
	double y[5];
	double z[] = { 9.9, 8.8, 7.7, 6.6, 5.6 };

	ArrayUtility::intToDouble(x, y, 5); // x[] -> y[]
	for (int i = 0; i < 5; i++) cout << y[i] << ' ';
	cout << endl;

	ArrayUtility::doubleToInt(z, x, 5); // z[] -> x[]
	for (int i = 0; i < 5; i++) cout << x[i] << ' ';
	cout << endl;
}

/* 아래는 참고로
	정수 배열과 실수 배열을 키로 입력받아 변환하는 코드를 보여준다.

int main() {
	int x[5];
	double y[5], z[5];

	cout << "정수를 5 개 입력하라. 배열에 삽입한다>>";
	for(int i=0; i<5; i++) cin >> x[i];

	cout << "정수 배열을 double 배열에 저장하고 결과를 출력한다->";
	ArrayUtility::intToDouble(x, y, 5); // x[] -> y[]

	for(int i=0; i<5; i++) cout << y[i] << ' ';
	cout << endl;

	cout << "실수를 5 개 입력하라. 배열에 삽입한다>>";
	for(int i=0; i<5; i++) cin >> z[i];

	cout << "실수 배열을 int 배열에 저장하고 결과를 출력한다->";
	ArrayUtility::doubleToInt(z, x, 5); // z[] -> x[]

	for(int i=0; i<5; i++) cout << x[i] << ' ';
	cout << endl;
}

*/