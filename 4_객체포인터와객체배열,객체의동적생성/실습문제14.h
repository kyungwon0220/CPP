#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

class Player {
	string name; // 선수 이름
	int *num = new int[3]; // 랜덤한 3개의 숫자
public:
	Player(string name) { this->name = name; }
	string getName() { return this->name; }
	void setNum(int *num) { this->num = num; }
	unsigned short checkNum(); // 선수가 가진 랜덤한 3개의 숫자를, 게임에서 이기는 조건(동일한지 체킹 함수
	void printNum();
};

class GamblingGame {
	Player* p;
public:
	GamblingGame(string user1name, string user2name) { p = new Player[2]{ user1name, user2name }; }
	void run();
};