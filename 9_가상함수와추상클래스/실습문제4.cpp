// 다음 추상 클래스 LoopAdder가 있다.
// LoopAdder 클래스를 상속받아 다음 main() 함수와 실행 결과처럼 되도록 WhileLoopAdder, DoWhileLoopAdder 클래스를 작성하라.
// while 문, do-while 문을 이용하여 합을 구하도록 calculate() 함수를 각각 작성하면 된다.

#include <iostream>

using namespace std;

class LoopAdder { // 추상 클래스
	string name; // 루프의 이름
	int x, y, sum; // x에서 y까지의 합은 sum
	void read() { // x, y 값을 읽어 들이는 함수
		cout << name << ":" << endl;
		cout << "처음 수에서 두번째 수까지 더합니다. 두 수를 입력하세요 >> ";
		cin >> x >> y;
	}
	void write() { // sum을 출력하는 함수
		cout << x << "에서 " << y << "까지의 합 = " << sum << " 입니다" << endl;
	}
protected:
	LoopAdder(string name = "") { this->name = name; /* 루프의 이름을 받는다. 초깃값은 "" */ } // 생성자
	int getX() { return x; }
	int getY() { return y; }
	virtual int calculate() = 0; // 순수 가상 함수. 루프를 돌며 합을 구하는 함수
public:
	void run() { // 연산을 진행하는 함수
		read(); // x, y를 읽는다.
		sum = calculate(); // 루프를 돌면서 계산한다.
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
	WhileLoopAdder(string name) : LoopAdder(name) {} // 생성자
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
	DoWhileLoopAdder(string name) : LoopAdder(name) {} // 생성자
};
int main() {
	WhileLoopAdder whileLoop("While Loop");
	DoWhileLoopAdder doWhileLoop("Do while Loop");

	whileLoop.run();
	doWhileLoop.run();
}