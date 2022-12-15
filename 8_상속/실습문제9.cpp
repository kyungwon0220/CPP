#include "실습문제9.h"

unsigned short console::selectMenu() {
	cout << "예약:1, 취소:2, 보기:3, 끝내기:4>>";
	unsigned short sel;
	cin >> sel;
	return sel;
}

unsigned short console::selectTime() {
	cout << "07시:1, 12시:2, 17시:3>> ";
	unsigned short sel;
	cin >> sel;
	return sel;
}

unsigned short console::selectSeatNum() {
		cout << "좌석 번호>> ";
		unsigned short num;
		cin >> num;
		return num;
}

string console::userName() {
	cout << "이름 입력>> ";
	string name;
	cin >> name;
	return name;
}


void Seat::setSeat(string name) { this->name = name; this->check = false; } // 예약

void Seat::resetSeat() { this->name = "---"; this->check = true; } // 예약 취소시


void Schedule::show() { // 보기
	cout << this->scName << "시:\t";
	for (unsigned short i = 0; i < 8; i++) cout << " " << seat[i].getName() << "\t";
	cout << endl;
}

void Schedule::resSeat(unsigned short num, string name) { this->seat[num].setSeat(name); } // 예약

void Schedule::cancelSeat(unsigned short num, string name) { // 예약 취소
	if (name.compare(this->seat[num].getName()) == 0) this->seat[num].resetSeat();
	else cout << "예약자명과 불일치하여, 예약 취소 불가" << endl;
}

void AirlineBook::start() {
	bool exit = true;

	while (exit) {
		unsigned short menu = console::selectMenu(); // 사용자로부터 메뉴 선택

		if (menu == 1 || menu == 2) {
			unsigned short time = console::selectTime() - 1; // 비행 시간

			switch (time) {
			case 0:
			case 1:
			case 2:
			{
				sc[time].show();

				unsigned short num = console::selectSeatNum() - 1; // 좌석 번호
				string name = console::userName(); // 사용자 이름

				if (menu == 1 && sc[time].checkSeat(num)) { // 예약을 원하는 좌석 번호가 비어있다면
					sc[time].resSeat(num, name);
				}
				else if (menu == 1 && (sc[time].checkSeat(num) == false)) {
					cout << "이미 예약된 좌석으로, 예약 불가" << endl;
					break;
				}
				else if (menu == 2 && (sc[time].checkSeat(num) == false)) {
					sc[time].cancelSeat(num, name);
				}
				else if (menu == 2 && sc[time].checkSeat(num)) {
					cout << "공석으로, 예약 취소 불가" << endl;
					break;
				}
				break;
			} // case end
			default:
				break;
			} // switch end
		}
		else if (menu == 3) { // 예약된 좌석 현황
			sc[0].show();
			sc[1].show();
			sc[2].show();
		}
		else { // 끝내기
			cout << "예약 시스템을 종료합니다.";
			exit = false;
			break;
		}
	} // while end
} // void start() end