#include "�ǽ�����14.h"

unsigned short Player::checkNum() {
	if (this->num[0] == this->num[1] && this->num[1] == this->num[2]) return 1; // �¸� ����
	else return 0;
}

void Player::printNum() { cout << this->num[0] << "\t" << this->num[1] << "\t" << this->num[2]; }


void GamblingGame::run() {
	unsigned short i = 0;
	char checkEnt;

	srand((unsigned)time(0)); // ������ ������, �ٸ� �������� �߻���Ű�� ���� seed ����


	while (1) {

		cout << p[i%2].getName() << ":";
		do { checkEnt = _getch(); } while (checkEnt != 13);
		cout << "<Enter>" << endl;
		
		int* tmp = new int[3];

		for (unsigned short j = 0; j < 3; j++) {			
			int random = (rand() *rand())% 3; // 0���� RAND_MAX(32767) ������ ������ ���� �߻�

			tmp[j] = random;
		}

		p[i % 2].setNum(tmp);

		//delete[] tmp;


		// ���ӿ��� �̱�� ���� üŷ
		if (p[i % 2].checkNum() == 1) {
			p[i % 2].printNum();
			cout << "\t" << p[i % 2].getName() << "�� �¸�!!" << endl;
			break; // i==0
		}
		else if(p[i % 2].checkNum() == 0) p[i % 2].printNum();
		
		cout << "\t�ƽ�����!" << endl;
		i++;
	};
}