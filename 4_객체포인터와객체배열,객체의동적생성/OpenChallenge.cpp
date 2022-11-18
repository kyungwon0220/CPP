#include "OpenChallenge.h"

void Player::setname(string name) { this->name = name; }

string Player::getname() { return this->name; }

WordGame::WordGame(unsigned short playerNum) {
	Player* p = new Player[playerNum];

	for (unsigned short i = 0; i < playerNum; i++) {
		string name;

		cout << "�������� �̸��� �Է��ϼ���. ��ĭ����>>";
		cin >> name;
		p[i].setname(name);
		cout << endl;
	}
	
	cout << "�����ϴ� �ܾ�� �ƹ����Դϴ�" << endl;

	unsigned short i = 0;
	string fword = "�ƹ���"; // 6���� ����Ʈ�� ����. a.size()�� 6. 3�� �ƴ�
	string lword;
	while (1) {
		cout << p[i%playerNum].getname() << ">>";
		cin >> lword;
		
		if (fword.at(fword.length() - 2) == lword.at(0) && fword.at(fword.length() - 1) == lword.at(1)) { // �����ձ� ������ ���
			// �ѱ��� 2����Ʈ �ڵ�� ����ǹǷ�, string ��ü�� ����� �ѱ� ���ڿ����� �� ���ڸ� ���Ϸ��� �� ����Ʈ�� �Բ� ���Ͽ��� �Ѵ�.
			fword = lword;
			i++;
		}
		else { // �����ձ� ������ ���
			cout << p[i % playerNum].getname() << "\tŻ��!" << endl;
			break;
		}
	}

	delete[] p;
}