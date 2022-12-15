// 게임에는 Human, Monster, Food의 세 객체가 등장하며, 이들은 10x20 격자판에서 각각 정해진 규칙에 의해 움직인다.
// Human 객체는 사용자의 키에 의해 왼쪽(a 키), 아래(s 키), 위(d 키), 오른쪽(f 키)으로 한 칸씩 움직이고, Monster는 한 번에 2칸씩, 왼쪽, 아래, 위, 오른쪽 방향으로 랜덤하게 움직인다.
// Food는 5번 중에 3번은 제자리에 있고, 나머지 2번은 4가지 방향 중 랜덤하게 한 칸씩 움직인다.
// 게임은 Human이 Monster를 피해 Food를 먹으면(Food의 위치로 이동) 성공으로 끝나고, Monster가 Food를 먹거나 Human이 Monster에게 잡히면 실패로 끝난다.
// 다음은 각 객체의 이동을 정의하는 move()와 각 객체의 모양을 정의하는 getShape() 함수를 순수 가상 함수로 가진 추상 클래스 GameObject이다.
// GameObject를 상속받아 Human, Monster, Food 클래스를 작성하라.
// 그리고 전체적인 게임을 진행하는 Game 클래스와 main() 함수를 작성하고 프로그램을 완성하라.
// 키가 입력될 때마다 Human, Monster, Food 객체의 move()를 순서대로 호출한다.
// 게임이 진행되는 과정은 다음 그림과 같으며, 게임의 종료 조건에 일치하면 게임을 종료한다.

class GameObject { // 추상 클래스
protected:
	int distance; // 한 번 이동 거리
	int x, y; // 현재 위치
public:
	GameObject(int startX, int startY, int distance) { // 초기 위치와 이동거리 설정
		this->x = startX;
		this->y = startY;
		this->distance = distance;
	}
	virtual ~GameObject() {} // 가상 소멸자

	virtual void move() = 0; // 이동한 후 새로운 위치로 x, y 변경
	virtual char getShape() = 0; // 객체의 모양을 나타내는 문자 리턴
	/*
	* Human의 경우 'H'
	* Monster의 경우 'M'
	* Food의 경우 '@'
	*/

	int getX() { return x; }
	int getY() { return y; }
	bool collide(GameObject* p) { // 이 객체가 객체 p와 충돌했으면 true 리턴
		if (this->x == p->getX() && this->y == p->getY()) return true;
		else return false;
	}
};

#include <iostream>

using namespace std;

class Human : public GameObject {
public:
	Human() : GameObject(0, 0, 1) {} // 생성자

	void move() {
		char k;

		cout << "왼쪽(a), 아래(s), 위(d), 오른쪽(f) >> ";
		cin >> k;

		switch (k) {
		case 'a' : // 왼쪽
			if (this->y > 0) this->y -= this->distance;
			else cout << "이동 불가" << endl;

			break;
		case 's' : // 아래
			if (this->x < 9) this->x += this->distance;
			else cout << "이동 불가" << endl;

			break;
		case 'd' : // 위
			if (this->x > 0) this->x -= this->distance;
			else cout << "이동 불가" << endl;

			break;
		case 'f' : // 오른쪽
			if (this->y < 19) this->y += this->distance;
			else cout << "이동 불가" << endl;

			break;
		} // switch end
	} // void move() end
	char getShape() { return 'H'; }
}; // class Human end

class Monster : public GameObject {
public:
	Monster(int rx = 5, int ry = 5) : GameObject(rx, ry, 2) {} // 생성자

	void move() {
		bool moveBool = false;

		do {
			switch (rand() % 4) {
			case 0: // 왼쪽
				if (this->y > 1) {
					this->y -= this->distance;
					break;
				}
			case 1: // 아래
				if (this->x < 8) {
					this->x += this->distance;
					break;
				}
			case 2: // 위
				if (this->x > 1) {
					this->x -= this->distance;
					break;
				}
			case 3: // 오른쪽
				if (this->y < 18) {
					this->y += this->distance;
					break;
				}
				else moveBool = true;

				break;
			} // switch end
		} while (moveBool);
	} // void move() end
	char getShape() { return 'M'; }
};

class Food : public GameObject {
	unsigned short moveStack;
public:
	Food() : GameObject(9, 9, 1) { this->moveStack = 0; } // 생성자

	void move() {
		bool moveBool = false;

		do {
			switch (rand() % 4) {
			case 0: // 왼쪽
				if (this->y > 0) {
					this->y -= this->distance;
					break;
				}
			case 1: // 아래
				if (this->x < 9) {
					this->x += this->distance;
					break;
				}
			case 2: // 위
				if (this->x > 0) {
					this->x -= this->distance;
					break;
				}
			case 3: // 오른쪽
				if (this->y < 19) {
					this->y += this->distance;
					break;
				}
				else moveBool = true;

				break;
			} // switch end
		} while (moveBool);
	} // void move() end
	char getShape() { return '@'; }
	unsigned short getStack() { return this->moveStack; }
};

class Game {
	char board[10][20]; // 10X20 격자판
	Human* h = new Human;
	Monster* m;
	Food* f = new Food;
public:
	Game() { // 생성자
		srand((unsigned)time(0));
		m = new Monster(rand() % 10, rand() % 20);
		cout << "** Human의 Food 먹기 게임을 시작합니다. **" << endl;

		for (unsigned short i = 0; i < 10; i++) {
			for (unsigned short j = 0; j < 20; j++) {
				this->board[i][j] = '-';
			}
		}
	}

	void readyXY() {
		this->board[h->getX()][h->getY()] = '-';
		this->board[m->getX()][m->getY()] = '-';
		this->board[f->getX()][f->getY()] = '-';
	}

	void setXY() {
		this->board[m->getX()][m->getY()] = m->getShape();
		this->board[f->getX()][f->getY()] = f->getShape();
		this->board[h->getX()][h->getY()] = h->getShape();
	}

	void show() {
		system("cls");
		for (unsigned short i = 0; i < 10; i++) {
			for (unsigned short j = 0; j < 20; j++) {
				cout << board[i][j];
			}
			cout << endl;
		}		
	}

	void game() {
		static unsigned short fTurn = 0; // Food 움직임 數
		static unsigned short gameTurn = 0;

		while (1) {
			gameTurn++;
			srand((unsigned)time(0));

			this->setXY();
			this->show();
			this->readyXY();

			this->h->move();
			this->m->move();
			
			if ((rand() % 2 == 0) && fTurn < 2 && gameTurn < 6) {
				f->move();
				fTurn++;
			}
			if (fTurn < 2 && gameTurn > 3) {
				f->move();
				fTurn++;
			}
			
			if (m->collide(this->h) || h->collide(this->m) || m->collide(this->f)) {
				this->readyXY();
				this->setXY();
				board[m->getX()][m->getY()] = 'M';
				this->show();

				cout << "Monster is Winner!!" << endl;
				break;
			}else if (h->collide(this->f)) { // Human이 Food 먹음
				this->readyXY();
				this->setXY();
				board[h->getX()][h->getY()] = 'H';
				this->show();

				cout << "Human is Winner!!" << endl;
				break;
			}

			if (gameTurn % 5 == 0) { gameTurn = 0; fTurn = 0; }
		} // while end
	} // void game() end

	
};


int main() {
	Game* g = new Game;

	g->game();

	delete g;
}