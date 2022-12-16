// 다음 AbstractStack은 정수 스택 클래스로서 추상 클래스이다.
// 이를 상속받아 정수를 푸시, 팝하는 IntStack 클래스를 만들고 사용 사례를 보여라.

#include <iostream>

using namespace std;

class AbstractStack { // 추상 클래스
public:
	virtual bool push(int n) = 0; // 스택에 n을 푸시한다. 스택이 full이면 false 리턴
	virtual bool pop(int& n) = 0; // 스택에서 팝한 정수를 n에 저장하고 스택이 empty이면 false 리턴

	virtual int size() = 0; // 현재 스택에 저장된 정수의 개수 리턴
};

class IntStack : public AbstractStack {
	int* stack;
	int stackSize;
	int index; // 스택에 저장된 정수의 개수
	virtual int size() { return this->index; }
public:
	IntStack(int n) { this->stackSize = n; this->stack = new int[stackSize]; this->index = 0; } // 생성자
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

	for (unsigned short j = 0; j < 10; j++) { // 처음 5 개를 성공적으로 push되고 다음 5 개는 스택 full로 push 실패
		if(i.push(j)) cout << "값\t" << j << "\tpush 성공" << endl;
		else cout << "스택 full" << endl;
	}

	for (unsigned short j = 0; j < 10; j++) { // 처음 5 개를 성공적으로 pop되고 다음 5 개는 스택 empty로 pop 실패
		if(i.pop(check[j])) cout << "값\t" << check[j] << "\tpop 성공" << endl;
		else cout << "스택 empty" << endl;
	}
}