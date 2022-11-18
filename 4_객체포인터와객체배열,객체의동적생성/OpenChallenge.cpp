#include "OpenChallenge.h"

void Player::setname(string name) { this->name = name; }

string Player::getname() { return this->name; }

WordGame::WordGame(unsigned short playerNum) {
	Player* p = new Player[playerNum];

	for (unsigned short i = 0; i < playerNum; i++) {
		string name;

		cout << "참가자의 이름을 입력하세요. 빈칸없이>>";
		cin >> name;
		p[i].setname(name);
		cout << endl;
	}
	
	cout << "시작하는 단어는 아버지입니다" << endl;

	unsigned short i = 0;
	string fword = "아버지"; // 6개의 바이트에 저장. a.size()는 6. 3이 아님
	string lword;
	while (1) {
		cout << p[i%playerNum].getname() << ">>";
		cin >> lword;
		
		if (fword.at(fword.length() - 2) == lword.at(0) && fword.at(fword.length() - 1) == lword.at(1)) { // 끝말잇기 성공한 경우
			// 한글은 2바이트 코드로 저장되므로, string 객체에 저장된 한글 문자열에서 끝 글자를 비교하려면 두 바이트를 함께 비교하여야 한다.
			fword = lword;
			i++;
		}
		else { // 끝말잇기 실패한 경우
			cout << p[i % playerNum].getname() << "\t탈락!" << endl;
			break;
		}
	}

	delete[] p;
}