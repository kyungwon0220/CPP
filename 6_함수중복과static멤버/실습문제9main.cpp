// 게시판 프로그램을 작성해보자.
// 멀티태스킹의 경우 여러 사용자들이 게시판에 글을 올리기 때문에 게시판 객체는 전체 하나만 있어야 한다.
// 그러므로 게시판 객체의 멤버들은 static으로 작성한다.
// 다음은 게시판 기능을 하는 Board 클래스를 활용하는 main() 코드이다.
// 실행 결과를 참고하여 Board 클래스를 만들고 전체 프로그램을 완성하라.
// static 연습이 목적이기 때문에 게시판 기능을 글을 올리는 기능과 게시글을 모두 출력하는 기능으로 제한하고 main()도 단순화하였다.

#include "실습문제9.h"

/*
* Board 클래스에는 게시글을 저장하기 위한 string 배열과 다음 저장할 위치 정보를 가진 static 멤버 변수가 필요하다.
* static 멤버 변수는 본문의 그림 6-8과 같이 전역 변수로 선언하는 것이 반드시 필요하다.
*/
unsigned short Board::i = 0; // static 멤버 변수를 전역 변수로 선언
string* Board::s = new string[3]; // static 멤버 변수를 전역 변수로 선언

int main() {
	// Board myBoard; // 객체 생성은 컴파일 오류입니다.
	Board::add("중간고사는 감독 없는 자율 시험입니다.");
	Board::add("코딩 라운지 많이 이용해 주세요.");
	Board::print();
	Board::add("진소린 학생이 경진대회 입상하였습니다. 축하해주세요");
	Board::print();
}
