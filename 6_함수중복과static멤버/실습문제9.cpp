#include "�ǽ�����9.h"

void Board::add(string s) { Board::s[Board::i++] = s; }

void Board::print() {
	cout << "********** �Խ����Դϴ�. **********" << endl;

	for (unsigned short j = 0; j < Board::i; j++) cout << j << ": " << Board::s[j] << endl;

	cout << endl;
}