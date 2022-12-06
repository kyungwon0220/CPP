#include "실습문제9.h"

void Board::add(string s) { Board::s[Board::i++] = s; }

void Board::print() {
	cout << "********** 게시판입니다. **********" << endl;

	for (unsigned short j = 0; j < Board::i; j++) cout << j << ": " << Board::s[j] << endl;

	cout << endl;
}