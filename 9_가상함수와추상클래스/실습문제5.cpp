// 디지털 회로에서 기본적인 게이트로 OR 게이트, AND 게이트, XOR 게이트 등이 있다.
// 이들은 각각 두 입력 신호를 받아 OR 연산, AND 연산, XOR 연산을 수행한 결과를 출력한다.
// 이 게이트들을 각각 ORGate, XORGate, ANDGate 클래스로 작성하고자 한다.
// ORGate, XORGate, ANDGate 클래스가 AbstractGate를 상속받도록 작성하라.
// ANDGate, ORGate, XORGate를 활용하는 사례와 결과는 다음과 같다.

#include <iostream>

using namespace std;

class AbstractGate { // 추상 클래스
protected:
	bool x, y;
public:
	void set(bool x, bool y) { this->x = x; this->y = y; }
	virtual bool operation() = 0;
};

class ANDGate : public AbstractGate {
public:
	bool operation() { if (this->x && this->y) return true; else return false; }
};

class ORGate : public AbstractGate {
public:
	bool operation() { if (this->x || this->y) return true; else return false; }
};

class XORGate : public AbstractGate {
public:
	bool operation() { if (this->x != this->y) return true; else return false; }
};

int main() {
	ANDGate andGate;
	ORGate orGate;
	XORGate xorGate;

	andGate.set(true, false);
	orGate.set(true, false);
	xorGate.set(true, false);

	cout.setf(ios::boolalpha); // 불린 값을 "true", "false" 문자열로 출력할 것을 지시
	cout << andGate.operation() << endl; // AND 결과는 false
	cout << orGate.operation() << endl; // OR 결과는 true
	cout << xorGate.operation() << endl; // XOR 결과는 true
}