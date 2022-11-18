// n명이 하는 한글 끝말잇기 게임을 작성해보자.
// 아래의 결과와 같이 선수의 수를 입력받고, 선수 각 사람의 이름을 입력받아 게임을 시작한다.


#include "OpenChallenge.h"


int main() {
	unsigned short playerNum;


	cout << "끝말 잇기 게임을 시작합니다" << endl << "게임에 참가하는 인원은 몇명입니까?";
	cin >> playerNum;

	WordGame game(playerNum);
}