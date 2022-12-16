// ���� �߻� Ŭ���� LoopAdder�� �ִ�.
// LoopAdder Ŭ������ ��ӹ޾� ���� main() �Լ��� ���� ���ó�� �ǵ��� WhileLoopAdder, DoWhileLoopAdder Ŭ������ �ۼ��϶�.
// while ��, do-while ���� �̿��Ͽ� ���� ���ϵ��� calculate() �Լ��� ���� �ۼ��ϸ� �ȴ�.

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

class WhileLoopAdder : public LoopAdder {
	int calculate() {
		int sum = 0;
		int count = this->getX();

		while (count <= this->getY()) {
			sum += count++;
		}

		return sum;
	}
public:
	WhileLoopAdder(string name) : LoopAdder(name) {} // ������
};

class DoWhileLoopAdder : public LoopAdder {
	int calculate() {
		int sum = 0;
		int count = this->getX();

		do {
			sum += count++;
		} while (count <= this->getY());

		return sum;
	}
public:
	DoWhileLoopAdder(string name) : LoopAdder(name) {} // ������
};
int main() {
	WhileLoopAdder whileLoop("While Loop");
	DoWhileLoopAdder doWhileLoop("Do while Loop");

	whileLoop.run();
	doWhileLoop.run();
}