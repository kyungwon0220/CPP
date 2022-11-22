#include "실습문제14.h"

unsigned short Player::checkNum() {
	if (this->num[0] == this->num[1] && this->num[1] == this->num[2]) return 1; // 승리 조건
	else return 0;
}

void Player::printNum() { cout << this->num[0] << "\t" << this->num[1] << "\t" << this->num[2]; }


void GamblingGame::run() {
	unsigned short i = 0;
	char checkEnt;

	srand((unsigned)time(0)); // 시작할 때마다, 다른 랜덤수를 발생시키기 위한 seed 설정


	while (1) {

		cout << p[i%2].getName() << ":";
		do { checkEnt = _getch(); } while (checkEnt != 13);
		cout << "<Enter>" << endl;
		
		int* tmp = new int[3];

		for (unsigned short j = 0; j < 3; j++) {			
			int random = (rand() *rand())% 3; // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수 발생

			tmp[j] = random;
		}

		p[i % 2].setNum(tmp);

		//delete[] tmp;


		// 게임에서 이기는 조건 체킹
		if (p[i % 2].checkNum() == 1) {
			p[i % 2].printNum();
			cout << "\t" << p[i % 2].getName() << "님 승리!!" << endl;
			break; // i==0
		}
		else if(p[i % 2].checkNum() == 0) p[i % 2].printNum();
		
		cout << "\t아쉽군요!" << endl;
		i++;
	};
}