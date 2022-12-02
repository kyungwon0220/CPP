// 동일한 크기의 배열을 변환하는 다음 2개의 static 멤버 함수를 가진 Arrayutility2 클래스를 만들고, 이 클래스를 이용하여 아래 결과와 같이 출력되도록 프로그램을 작성하라.

#include "실습문제6.h"


int main() {
	int x[5], y[5], *z;
	int retSize;

	cout << "정수를 5 개 입력하라. 배열에 삽입한다>>";
	for (int i = 0; i < 5; i++) cin >> x[i];
	cout << "정수를 5 개 입력하라. 배열에 삽입한다>>";
	for (int i = 0; i < 5; i++) cin >> y[i];

	cout << "합친 정수 배열을 출력한다" << endl;
	for (unsigned short i = 0; i < 10; i++) cout << ArrayUtility2::concat(x, y, 5)[i] << ' ';
	cout << endl;

	z = ArrayUtility2::remove(x, y, 5, retSize);
	cout << "배열 x[]에서 y[]를 뺀 결과를 출력한다. 개수는 " << retSize << endl;
	for (unsigned short i = 0; i < retSize; i++) cout << z[i] << ' ';
}