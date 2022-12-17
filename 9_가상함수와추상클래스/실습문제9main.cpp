// 다음 그림과 같은 상속 구조를 갖는 클래스를 설계한다.
// 모든 프린터는 모델명(model), 제조사(manufacturer), 인쇄 매수(printedCount), 인쇄 종이 잔량(availableCount)을 나타내는 정보를 가진다.
// print(int pages) 함수와 show() 함수는 가상 함수로 구현하라.
// print(int pages)는 pages 만큼 프린트 하는 함수이고, show() 함수는 현재 프린트의 모델, 제조사, 인쇄 매수, 인쇄 종이 잔량 등을 출력하는 함수이다.
// 잉크젯 프린터는 잉크 잔량(availableInk) 정보를 추가적으로 가지며, 레이저 프린터는 토너 잔량(availableToner) 정보를 추가적으로 가진다.
// 이들의 print(int pages) 멤버 함수는 프린터 타입에 맞게 구현하라.
// 각 클래스를 설계 구현하고 다음과 같이 실행되도록 전체 프로그램을 완성하라.
// InkJetPrinter 객체와 LaserPrinter 객체를 각각 하나만 동적으로 생성하여 시작한다.

#include "실습문제9.h"

int main() {
	InkJetPrinter* IP = new InkJetPrinter("Officejet V40", "HP", 5, 10);
	LaserPrinter* LP = new LaserPrinter("SCX-6x45", "삼성전자", 3, 20);
	bool exit = true;

	cout << "현재 작동중인 2 대의 프린터는 아래와 같다." << endl;
	cout << "잉크젯 : ";
	IP->show();
	cout << "레이저 : ";
	LP->show();
	cout << endl;

	do {
		unsigned short sel, pages;
		char k;

		cout << endl << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		cin >> sel >> pages;

		switch (sel) {
		case 1:
			IP->print(pages);
			break;
		case 2:
			LP->print(pages);
			break;
		default:
			break;
		}

		IP->show();
		LP->show();
		cout << "계속 프린트 하시겠습니까?(y/n)>>";
		cin >> k;
		if (k != 'y') exit = false;
	} while (exit);
}