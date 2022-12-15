// 모든 프린터는 모델명(model), 제조사(manufacturer), 인쇄 매수(printedCount), 인쇄 종이 잔량(availableCount)을 나타내는 정보와 print(int pages) 멤버 함수를 가지며, print()가 호출할 때마다 pages 매의 용지를 사용한다.
// 잉크젯 프린터는 잉크 잔량(availableInk) 정보와 printInkJet(int pages) 멤버 함수를 추가적으로 가지며, 레이저 프린터는 토너 잔량(availableToner) 정보와 역시 printLaser(int pages) 멤버 함수를 추가적으로 가진다.
// 각 클래스에 적절한 접근 지정으로 멤버 변수와 함수, 생성자, 소멸자를 작성하고, 다음과 같이 실행되도록 전체 프로그램을 완성하라.
// 잉크젯 프린터 객체와 레이저 프린터 객체를 각각 하나만 동적 생성하여 시작한다.

#include "실습문제8.h"


int main() {
	InkJetPrinter* inkjetp = new InkJetPrinter("Officejet V40", "HP", 5, 10);
	LaserPrinter* laserp = new LaserPrinter("SCX-6x45", "삼성전자", 3, 20);
	bool exit = true;

	cout << "현재 작동중인 2 대의 프린터는 아래와 같다" << endl;
	cout << "잉크젯 : ";
	inkjetp->show();
	cout << "레이저 : ";
	laserp->show();

	do {
		unsigned short needCount, sel;

		cout << endl << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		
		cin >> sel >> needCount;

		switch (sel) {
		case 1: {
			inkjetp->printInkJet(needCount);
			inkjetp->show();
			laserp->show();

			char c;
			cout << "계속 프린트 하시겠습니까(y/n)>>";
			cin >> c;
			if (c == 'n') {
				exit = false;
				break;
			} else if (c == 'y') break;
		} // case1 end
		case 2: {
			laserp->printLaser(needCount);
			inkjetp->show();
			laserp->show();

			char c;
			cout << "계속 프린트 하시겠습니까(y/n)>>";
			cin >> c;
			if (c == 'n') {
				exit = false;
				break;
			}
			else if (c == 'y') break;
		} // case2 end
		default:
			break;
		}
	} while (exit);
} // main end