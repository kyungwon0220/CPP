// main()의 실행 결과가 다음과 같도록 Tower 클래스를 작성하라.


#include "실습문제1Re1.h"

using namespace std;

int main() {
	Tower myTower; // 1 미터
	Tower seoulTower(100); // 100 미터

	cout << "높이는 " << myTower.getHeight() << "미터" << endl;
	cout << "높이는 " << seoulTower.getHeight() << "미터" << endl;
}