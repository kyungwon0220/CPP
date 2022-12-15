// ���ӿ��� Human, Monster, Food�� �� ��ü�� �����ϸ�, �̵��� 10x20 �����ǿ��� ���� ������ ��Ģ�� ���� �����δ�.
// Human ��ü�� ������� Ű�� ���� ����(a Ű), �Ʒ�(s Ű), ��(d Ű), ������(f Ű)���� �� ĭ�� �����̰�, Monster�� �� ���� 2ĭ��, ����, �Ʒ�, ��, ������ �������� �����ϰ� �����δ�.
// Food�� 5�� �߿� 3���� ���ڸ��� �ְ�, ������ 2���� 4���� ���� �� �����ϰ� �� ĭ�� �����δ�.
// ������ Human�� Monster�� ���� Food�� ������(Food�� ��ġ�� �̵�) �������� ������, Monster�� Food�� �԰ų� Human�� Monster���� ������ ���з� ������.
// ������ �� ��ü�� �̵��� �����ϴ� move()�� �� ��ü�� ����� �����ϴ� getShape() �Լ��� ���� ���� �Լ��� ���� �߻� Ŭ���� GameObject�̴�.
// GameObject�� ��ӹ޾� Human, Monster, Food Ŭ������ �ۼ��϶�.
// �׸��� ��ü���� ������ �����ϴ� Game Ŭ������ main() �Լ��� �ۼ��ϰ� ���α׷��� �ϼ��϶�.
// Ű�� �Էµ� ������ Human, Monster, Food ��ü�� move()�� ������� ȣ���Ѵ�.
// ������ ����Ǵ� ������ ���� �׸��� ������, ������ ���� ���ǿ� ��ġ�ϸ� ������ �����Ѵ�.

class GameObject { // �߻� Ŭ����
protected:
	int distance; // �� �� �̵� �Ÿ�
	int x, y; // ���� ��ġ
public:
	GameObject(int startX, int startY, int distance) { // �ʱ� ��ġ�� �̵��Ÿ� ����
		this->x = startX;
		this->y = startY;
		this->distance = distance;
	}
	virtual ~GameObject() {} // ���� �Ҹ���

	virtual void move() = 0; // �̵��� �� ���ο� ��ġ�� x, y ����
	virtual char getShape() = 0; // ��ü�� ����� ��Ÿ���� ���� ����
	/*
	* Human�� ��� 'H'
	* Monster�� ��� 'M'
	* Food�� ��� '@'
	*/

	int getX() { return x; }
	int getY() { return y; }
	bool collide(GameObject* p) { // �� ��ü�� ��ü p�� �浹������ true ����
		if (this->x == p->getX() && this->y == p->getY()) return true;
		else return false;
	}
};

#include <iostream>

using namespace std;

class Human : public GameObject {
public:
	Human() : GameObject(0, 0, 1) {} // ������

	void move() {
		char k;

		cout << "����(a), �Ʒ�(s), ��(d), ������(f) >> ";
		cin >> k;

		switch (k) {
		case 'a' : // ����
			if (this->y > 0) this->y -= this->distance;
			else cout << "�̵� �Ұ�" << endl;

			break;
		case 's' : // �Ʒ�
			if (this->x < 9) this->x += this->distance;
			else cout << "�̵� �Ұ�" << endl;

			break;
		case 'd' : // ��
			if (this->x > 0) this->x -= this->distance;
			else cout << "�̵� �Ұ�" << endl;

			break;
		case 'f' : // ������
			if (this->y < 19) this->y += this->distance;
			else cout << "�̵� �Ұ�" << endl;

			break;
		} // switch end
	} // void move() end
	char getShape() { return 'H'; }
}; // class Human end

class Monster : public GameObject {
public:
	Monster(int rx = 5, int ry = 5) : GameObject(rx, ry, 2) {} // ������

	void move() {
		bool moveBool = false;

		do {
			switch (rand() % 4) {
			case 0: // ����
				if (this->y > 1) {
					this->y -= this->distance;
					break;
				}
			case 1: // �Ʒ�
				if (this->x < 8) {
					this->x += this->distance;
					break;
				}
			case 2: // ��
				if (this->x > 1) {
					this->x -= this->distance;
					break;
				}
			case 3: // ������
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
	Food() : GameObject(9, 9, 1) { this->moveStack = 0; } // ������

	void move() {
		bool moveBool = false;

		do {
			switch (rand() % 4) {
			case 0: // ����
				if (this->y > 0) {
					this->y -= this->distance;
					break;
				}
			case 1: // �Ʒ�
				if (this->x < 9) {
					this->x += this->distance;
					break;
				}
			case 2: // ��
				if (this->x > 0) {
					this->x -= this->distance;
					break;
				}
			case 3: // ������
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
	char board[10][20]; // 10X20 ������
	Human* h = new Human;
	Monster* m;
	Food* f = new Food;
public:
	Game() { // ������
		srand((unsigned)time(0));
		m = new Monster(rand() % 10, rand() % 20);
		cout << "** Human�� Food �Ա� ������ �����մϴ�. **" << endl;

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
		static unsigned short fTurn = 0; // Food ������ �
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
			}else if (h->collide(this->f)) { // Human�� Food ����
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