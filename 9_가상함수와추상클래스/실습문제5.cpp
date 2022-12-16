// ������ ȸ�ο��� �⺻���� ����Ʈ�� OR ����Ʈ, AND ����Ʈ, XOR ����Ʈ ���� �ִ�.
// �̵��� ���� �� �Է� ��ȣ�� �޾� OR ����, AND ����, XOR ������ ������ ����� ����Ѵ�.
// �� ����Ʈ���� ���� ORGate, XORGate, ANDGate Ŭ������ �ۼ��ϰ��� �Ѵ�.
// ORGate, XORGate, ANDGate Ŭ������ AbstractGate�� ��ӹ޵��� �ۼ��϶�.
// ANDGate, ORGate, XORGate�� Ȱ���ϴ� ��ʿ� ����� ������ ����.

#include <iostream>

using namespace std;

class AbstractGate { // �߻� Ŭ����
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

	cout.setf(ios::boolalpha); // �Ҹ� ���� "true", "false" ���ڿ��� ����� ���� ����
	cout << andGate.operation() << endl; // AND ����� false
	cout << orGate.operation() << endl; // OR ����� true
	cout << xorGate.operation() << endl; // XOR ����� true
}