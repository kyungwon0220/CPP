// main()의 실행 결과가 다음과 같도록 Tower 클래스를 작성하라.
/*
* 높이는 1미터
* 높이는 100미터
*/
#include <iostream>

using namespace std;

//

class Tower {
private:
	int Height;
public:
	Tower();
	Tower(int Height);

	int getHeight() { return this->Height; }
};

Tower::Tower() : Tower(1) {} // 위임 생성자
Tower::Tower(int Height) { this->Height = Height; }

//

int main() {
	Tower myTower; // 1 미터
	Tower seoulTower(100); // 100 미터
	cout << "높이는 " << myTower.getHeight() << "미터" << endl;
	cout << "높이는 " << seoulTower.getHeight() << "미터" << endl;
}