// 다음 Circle 클래스가 있다.
// Circle 객체 b를 a에 더하여 a를 키우고자 다음 함수를 작성하였다.
// 다음 코드를 실행하면 increaseBy() 함수는 목적대로 실행되는가?
// main() 함수의 목적을 달성하도록 increaseBy() 함수를 수정하라.


#include <iostream>

using namespace std;

class Circle {
	int radius;
public:
	Circle(int r) { radius = r; }
	int getRadius() { return radius; }
	void setRadius(int r) { radius = r; }
	void show() { cout << "반지름이" << radius << "인 원" << endl; }
};

void increaseBy(Circle &a, Circle b) { // 참조에 의한 호출 必
	int r = a.getRadius() + b.getRadius();
	a.setRadius(r);
}

int main() {
	Circle x(10), y(5);
	increaseBy(x, y); // x의 반지름이 15인 원을 만들고자 한다.
	x.show(); // "반지름이 15인 원"을 출력한다.
}