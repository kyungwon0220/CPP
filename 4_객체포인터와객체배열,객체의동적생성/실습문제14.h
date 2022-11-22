#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

class Player {
	string name; // ���� �̸�
	int *num = new int[3]; // ������ 3���� ����
public:
	Player(string name) { this->name = name; }
	string getName() { return this->name; }
	void setNum(int *num) { this->num = num; }
	unsigned short checkNum(); // ������ ���� ������ 3���� ���ڸ�, ���ӿ��� �̱�� ����(�������� üŷ �Լ�
	void printNum();
};

class GamblingGame {
	Player* p;
public:
	GamblingGame(string user1name, string user2name) { p = new Player[2]{ user1name, user2name }; }
	void run();
};