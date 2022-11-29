// 아래와 같이 원형이 주어진 bigger()를 작성하고 사용자로부터 2개의 정수를 입력받아 큰 값을 출력하는 main()을 작성하라.
// bigger()는 인자로 주어진 a, b가 같으면 true, 아니면 false를 리턴하고 큰 수는 big에 전달하라.


#include "실습문제4.h"

int main() {
	int a, b, big;

	cout << "두 정수를 입력하세요>> ";
	cin >> a >> b;

	if (bigger(a, b, big) == true) cout << "same" << endl;
	else cout << "큰 수는 " << big << endl;
}