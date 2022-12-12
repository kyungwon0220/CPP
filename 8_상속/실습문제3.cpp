// ���� 3~4�� ����Ǵ� 2���� ���� �� ���� ǥ�q�� Point Ŭ������ �ִ�.
// ���� main() �Լ��� ����ǵ��� Point Ŭ������ ��ӹ��� ColorPoint Ŭ������ �ۼ��ϰ�, ��ü ���α׷��� �ϼ��϶�.

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
	ColorPoint(int x, int y, string name) : Point(x, y) { this->name = name; }
	void setPoint(int x, int y) { this->move(x, y); }
	void setColor(string name) { this->name = name; }
	void show() { cout << this->name << "������ (" << this->getX() << "," << this->getY() << ")�� ��ġ�� ���Դϴ�." << endl; }
};

int main() {
	ColorPoint cp(5, 5, "RED");
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();
}