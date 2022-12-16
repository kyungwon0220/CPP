// ���� AbstractStack�� ���� ���� Ŭ�����μ� �߻� Ŭ�����̴�.
// �̸� ��ӹ޾� ������ Ǫ��, ���ϴ� IntStack Ŭ������ ����� ��� ��ʸ� ������.

#include <iostream>

using namespace std;

class AbstractStack { // �߻� Ŭ����
public:
	virtual bool push(int n) = 0; // ���ÿ� n�� Ǫ���Ѵ�. ������ full�̸� false ����
	virtual bool pop(int& n) = 0; // ���ÿ��� ���� ������ n�� �����ϰ� ������ empty�̸� false ����

	virtual int size() = 0; // ���� ���ÿ� ����� ������ ���� ����
};

class IntStack : public AbstractStack {
	int* stack;
	int stackSize;
	int index; // ���ÿ� ����� ������ ����
	virtual int size() { return this->index; }
public:
	IntStack(int n) { this->stackSize = n; this->stack = new int[stackSize]; this->index = 0; } // ������
	virtual ~IntStack() { if (this->stack) delete[] this->stack; }
	bool push(int n) {
		if (this->stackSize <= this->index) return false; // full
		else {
			this->stack[this->index++] = n;
			return true;
		}
	}
	bool pop(int& n) {
		if (this->index == 0) return false; // empty
		else {
			n = this->stack[--index];
			return true;
		}

	}
	
};


int main() {
	IntStack i(5);
	int check[5] = { 0, };

	for (unsigned short j = 0; j < 10; j++) { // ó�� 5 ���� ���������� push�ǰ� ���� 5 ���� ���� full�� push ����
		if(i.push(j)) cout << "��\t" << j << "\tpush ����" << endl;
		else cout << "���� full" << endl;
	}

	for (unsigned short j = 0; j < 10; j++) { // ó�� 5 ���� ���������� pop�ǰ� ���� 5 ���� ���� empty�� pop ����
		if(i.pop(check[j])) cout << "��\t" << check[j] << "\tpop ����" << endl;
		else cout << "���� empty" << endl;
	}
}