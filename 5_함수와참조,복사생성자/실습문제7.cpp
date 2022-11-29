// 다음과 같이 선언된 정수를 저장하는 스택 클래스 MyIntStack을 구현하라.
// MyIntStack 스택에 저장할 수 있는 정수의 최대 개수는 10이다.
// MyIntStack 클래스를 활용하는 코드와 실행 결과는 다음과 같다.


#include <iostream>

using namespace std;

class MyIntStack {
	int p[10]; // 최대 10개의 정수 저장
	int tos; // 스택의 꼭대기를 가리키는 인덱스
public:
	MyIntStack() { this->tos=0; }
	bool push(int n) { // 정수 n 푸시. 꽉 차 있으면 false, 아니면 true 리턴
		if (this->tos == 10) return false;
		else {
			this->p[tos] = n;
			this->tos++;
			return true;
		}
	}
	bool pop(int& n) { // 팝하여 n에 저장. 스택이 비어 있으면 false, 아니면 true 리턴
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
	for (int i = 0; i < 11; i++) { // 11개를 푸시하면, 마지막에는 stack full이 된다.
		if (a.push(i)) cout << i << ' '; // 푸사된 값 에코
		else cout << endl << i + 1 << " 번째 stack full" << endl;
	}
	int n;
	for (int i = 0; i < 11; i++) { // 11개를 팝하면, 마지막에는 stack empty가 된다.
		if (a.pop(n)) cout << n << ' '; // 팝 한 값 출력
		else cout << endl << i + 1 << " 번째 stack empty";
	}
	cout << endl;
}