// ������ ���� ����� ������ �����ϴ� ���� Ŭ���� MyIntStack�� �����϶�.
// MyIntStack ���ÿ� ������ �� �ִ� ������ �ִ� ������ 10�̴�.
// MyIntStack Ŭ������ Ȱ���ϴ� �ڵ�� ���� ����� ������ ����.


#include <iostream>

using namespace std;

class MyIntStack {
	int p[10]; // �ִ� 10���� ���� ����
	int tos; // ������ ����⸦ ����Ű�� �ε���
public:
	MyIntStack() { this->tos=0; }
	bool push(int n) { // ���� n Ǫ��. �� �� ������ false, �ƴϸ� true ����
		if (this->tos == 10) return false;
		else {
			this->p[tos] = n;
			this->tos++;
			return true;
		}
	}
	bool pop(int& n) { // ���Ͽ� n�� ����. ������ ��� ������ false, �ƴϸ� true ����
		if (this->tos == 0) return false;
		else {
			this->tos--;
			n = this->p[this->tos];	
			return true;
		}
	}
};

int main() {
	MyIntStack a;
	for (int i = 0; i < 11; i++) { // 11���� Ǫ���ϸ�, ���������� stack full�� �ȴ�.
		if (a.push(i)) cout << i << ' '; // Ǫ��� �� ����
		else cout << endl << i + 1 << " ��° stack full" << endl;
	}
	int n;
	for (int i = 0; i < 11; i++) { // 11���� ���ϸ�, ���������� stack empty�� �ȴ�.
		if (a.pop(n)) cout << n << ' '; // �� �� �� ���
		else cout << endl << i + 1 << " ��° stack empty";
	}
	cout << endl;
}