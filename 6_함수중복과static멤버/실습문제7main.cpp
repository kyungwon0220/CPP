// 다음과 같은 static 멤버를 가진 Rando 클래스를 완성하라(Open Challenge 힌트 참고).
// 그리고 Random 클래스를 이용하여 다음과 같이 랜덤한 값을 출력하는 main() 함수도 작성하라.
// main()에서 Random 클래스의 seed() 함수를 활용하라.

#include "실습문제7.h"


int main() {
	Random r;

	Random::seed();

	cout << "1에서 100까지 랜덤한 정수 10개를 출력합니다" << endl;

	for(unsigned short i = 0; i < 10; i++) cout << r.nextInt(0, 101) << ' ';
	cout << endl;

	cout << "알파벳을 랜덤하게 10개를 출력합니다" << endl;
	for (unsigned short i = 0; i < 10; i++) cout << r.nextAlphabet() << ' ';
	cout << endl;

	cout << "랜덤한 실수를 10개를 출력합니다" << endl;
	for (unsigned short i = 0; i < 10; i++) cout << r.nextDouble() << ' ';
	cout << endl;
}
