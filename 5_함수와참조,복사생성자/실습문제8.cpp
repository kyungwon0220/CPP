// ���� 7���� MyIntStack�� �����Ͽ� ������ ���� �����Ͽ���.
// ���ÿ� ������ �� �ִ� ������ �ִ� ������ �����ڿ��� �־����� size ����� �����Ѵ�.
// MyIntStack Ŭ������ �ۼ��϶�.
// MyIntStack Ŭ������ Ȱ���ϴ� �ڵ�� ������ ����� ������ ����.


#include <iostream>

using namespace std;

class MyIntStack {
	int* p; // ���� �޸𸮷� ����� ������
	int size; // ������ �ִ� ũ��
	int tos; // ������ ����⸦ ����Ű�� �ε���
public:
	MyIntStack() : MyIntStack(1) {}

	MyIntStack(int size) {
		this->size = size;
		p = new int[size];
		tos = 0;
	}
	MyIntStack(const MyIntStack& s) { // ���� ������
		this->size = s.size;
		this->p = new int[s.size];
		this->tos = s.tos;

		for (unsigned short i = 0; i < s.size; i++) this->p[i] = s.p[i];
	}

	~MyIntStack() { delete[] p; }


	bool push(int n) { // ���� n�� ���ÿ� Ǫ���Ѵ�.
		// ������ �� �� ������ false��, �ƴϸ� true ����
		if (this->tos == this->size) return false;
		else {
			this->p[tos] = n;
			this->tos++;
			return true;
		}
	}
	bool pop(int& n) { // ������ ž�� �ִ� ���� n�� ���Ѵ�.
		// ���� ������ ��� ������ false��, �ƴϸ� true ����
		if (this->tos == 0) return false;
		else {
			this->tos--;
			n = this->p[this->tos];	
			return true;
		}
	}
};

int main() {
	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a; //  ���� ����
	b.push(30);

	int n;
	a.pop(n); // ���� a ��
	cout << "���� a���� ���� �� " << n << endl;
	b.pop(n); // ���� b ��
	cout << "���� b���� ���� �� " << n << endl;
}