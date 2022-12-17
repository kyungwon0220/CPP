// 간단한 그래픽 편집기를 콘솔 바탕으로 만들어보자.
// 그래픽 편집기의 기능은 "삽입", "삭제", "모두보기", "종료" 의 4가지이고, 실행 과정은 다음과 같다.
// Shape과 이를 상속받은 Circle, Line, Rect 클래스는 [그림9-13]을 이요하고 필요한 클래스와 main() 함수를 작성하라.
// 전체 프로그램은 대략 아래와 같이 구성된다.

#include "실습문제10.h"

int main() {
	GraphicEditor* g = new GraphicEditor;

	g->start();

	delete g;
}