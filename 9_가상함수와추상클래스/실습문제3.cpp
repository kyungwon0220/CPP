// ���� �߻� Ŭ���� LoopAdder�� �ִ�.
// LoopAdder Ŭ������ ��ӹ޾� ���� main() �Լ��� ���� ���ó�� �ǵ��� ForLoopAdder Ŭ������ �ۼ��϶�.
// ForLoopAdder Ŭ������ calculate() �Լ��� for ���� �̿��Ͽ� ���� ���Ѵ�.

#include <iostream>

using namespace std;

class LoopAdder { // �߻� Ŭ����
	string name; // ������ �̸�
	int x, y, sum; // x���� y������ ���� sum
	void read() { // x, y ���� �о� ���̴� �Լ�
		cout << name << ":" << endl;
		cout << "ó�� ������ �ι�° ������ ���մϴ�. �� ���� �Է��ϼ��� >> ";
		cin >> x >> y;
	}
	void write() { // sum�� ����ϴ� �Լ�
		cout << x << "���� " << y << "������ �� = " << sum << " �Դϴ�" << endl;
	}
protected:
	LoopAdder(string name = "") { this->name = name; /* ������ �̸��� �޴´�. �ʱ갪�� "" */ } // ������
	int getX() { return x; }
	int getY() { return y; }
	virtual int calculate() = 0; // ���� ���� �Լ�. ������ ���� ���� ���ϴ� �Լ�
public:
	void run() { // ������ �����ϴ� �Լ�
		read(); // x, y�� �д´�.
		sum = calculate(); // ������ ���鼭 ����Ѵ�.
		write();
	}
};

class ForLoopAdder : public LoopAdder {
	int calculate() {
		int sum = 0;

		for (unsigned short i = this->getX(); i <= this->getY(); i++) sum += i;

		return sum;
	}
public:
	ForLoopAdder(string name) : LoopAdder(name) {} // ������
};

int main() {
	ForLoopAdder forLoop("For Loop");
	forLoop.run();
}