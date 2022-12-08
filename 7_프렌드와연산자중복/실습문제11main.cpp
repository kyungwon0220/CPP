// 스택 클래스 Stack을 만들고 푸시(push)용으로 << 연산자를, 팝(pop)을 위해 >> 연산자를, 비어있는 스택인지를 알기 위해 ! 연산자를 작성하라.
// 다음 코드를 main()으로 작성하라.

#include "실습문제11.h"

int main() {
	Stack stack;
	stack << 3 << 5 << 10; // 3, 5, 10을 순서대로 푸시
	while (true) {
		if (!stack) break; // 스택 empty
		int x;
		stack >> x; // 스택의 탑에 있는 정수 팝
		cout << x << ' ';
	}
	cout << endl;
}