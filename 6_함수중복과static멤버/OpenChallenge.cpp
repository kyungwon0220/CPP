// Up & Down 게임 프로그램을 작성해보자.
// 게임에 참석하는 사람은 2명이며, 번갈아 가며 다음과 같이 숨겨진 답에 접근해 간다.
// Up & Down 게임은 전체적으로 UpAndDownGame 클래스로 작성하고 static 멤버로만 구성하라.
// 선수를 표현하기 위해 Person 클래스를 작성하고 main() 함수는 프로그램을 시작시키는 기능 정도로만 구현하라.


#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


class Person {
private:
	string name;	
public:
	Person(string name) { this->name = name; }
	string getName() { return this->name; }
	void setName(string name) { this->name = name; }
};

class UpAndDownGame {
private:
	static int random;
	static unsigned short loww;
	static unsigned short highh;
public:
	static void gameRun(){
		srand((unsigned)time(0)); // 항상 다른 랜덤수를 발생시키기 위한 seed 설정
		UpAndDownGame::random = rand()%100; // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수 % 100 == n

		Person* p = new Person[2]{ Person("김인수"), Person("오은경") };

		cout << "Up & Down 게임을 시작합니다." << endl;

		unsigned short i = 0;
		unsigned short check;

		do {
			cout << "답은 " << loww << "과 " << highh << "사이에 있습니다." << endl;
			cout << p[i % 2].getName() << ">>";
			cin >> check;

			cout << "nowRand:" << UpAndDownGame::random << endl;
			if (UpAndDownGame::random > check) UpAndDownGame::loww = check;
			else if (UpAndDownGame::random < check) UpAndDownGame::highh = check;
			else if (UpAndDownGame::random == check) cout << p[i % 2].getName() << "가 이겼습니다!!" << endl;

			i++;
		} while (check != UpAndDownGame::random);
		
	}
};

unsigned short UpAndDownGame::loww = 0;
unsigned short UpAndDownGame::highh = 99;
int UpAndDownGame::random;

int main() {	
	UpAndDownGame::gameRun();
}