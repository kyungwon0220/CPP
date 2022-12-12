// 문제 3~4에 적용되는 2차원 상의 한 점을 표혆는 Point 클래스가 있다.
// 다음 main() 함수가 실행되도록 Point 클래스를 상속받는 ClolorPoint 클래스를 작성하고, 전체 프로그램을 완성하라.
#include <iostream>

using namespace std;

class Point {
	int x, y;
public:
	Point(int x, int y) { this->x = x; this->y = y; }
	int getX() { return x; }
	int getY() { return y; }
protected:
	void move(int x, int y) { this->x = x; this->y = y; }
};

class ColorPoint : private Point {
	string name;
public:
	ColorPoint(int x=0, int y=0, string name="Black") : Point(x, y) { this->name = name; }
	void setPoint(int x, int y) { this->move(x, y); }
	void setColor(string name) { this->name = name; }
	void show() { cout << this->name << "색으로 (" << this->getX() << "," << this->getY() << ")에 위치한 점입니다." << endl; }
};

int main() {
	ColorPoint zeroPoint; // Black 색에 (0, 0) 위치의 점
	zeroPoint.show(); // zeroPoint를 출력한다.

	ColorPoint cp(5, 5);
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show(); // cp를 출력한다.
}