// 문제 7번의 MyIntStack를 수정하여 다음과 같이 선언하였다.
// 스택에 저장할 수 있는 정수의 최대 개수는 생성자에서 주어지고 size 멤버에 유지한다.
// MyIntStack 클래스를 작성하라.
// MyIntStack 클래스를 활용하는 코드오 ㅏ실행 결과는 다음과 같다.


#include <iostream>

using namespace std;

class MyIntStack {
	int* p; // 스택 메모리로 사용할 포인터
	int size; // 스택의 최대 크기
	int tos; // 스택의 꼭대기를 가리키는 인덱스
public:
	MyIntStack() : MyIntStack(1) {}

	MyIntStack(int size) {
		this->size = size;
		p = new int[size];
		tos = 0;
	}
	MyIntStack(const MyIntStack& s) { // 복사 생성자
		this->size = s.size;
		this->p = new int[s.size];
		this->tos = s.tos;

		for (unsigned short i = 0; i < s.size; i++) this->p[i] = s.p[i];
	}

	~MyIntStack() { delete[] p; }


	bool push(int n) { // 정수 n을 스택에 푸시한다.
		// 스택이 꽉 차 있으면 false를, 아니면 true 리턴
		if (this->tos == this->size) return false;
		else {
			this->p[tos] = n;
			this->tos++;
			return true;
		}
	}
	bool pop(int& n) { // 스택의 탑에 있는 값을 n에 팝한다.
		// 만일 스택이 비어 있으면 false를, 아니면 true 리턴
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
	MyIntStack b = a; //  복사 생성
	b.push(30);

	int n;
	a.pop(n); // 스택 a 팝
	cout << "스택 a에서 팝한 값 " << n << endl;
	b.pop(n); // 스택 b 팝
	cout << "스택 b에서 팝한 값 " << n << endl;
}