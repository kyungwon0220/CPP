#include <iostream>

using namespace std;

class console {
public:
	static unsigned short selectMenu();
	static unsigned short selectTime();
	static unsigned short selectSeatNum();
	static string userName();
};


class Seat {
	string name; // 예약자 이름
	bool check; // 예약된 상태 == false
public:
	Seat() { this->name = "---"; this->check = true; } // 생성자
	void setSeat(string name); // 예약
	void resetSeat(); // 예약 취소시, 공석으로

	string getName() { return this->name; }
	bool seatStat() { return this->check; } // 예약 현황
};


class Schedule { // 스케쥴
	string scName;
	Seat* seat;
public:
	Schedule(string scName) { this->seat = new Seat[8]; /* 8개의 좌석 */ this->scName = scName; } // 생성자
	virtual ~Schedule() { delete[] seat; } // 가상 소멸자

	void show();
	bool checkSeat(unsigned short num) { return seat[num].seatStat(); } // 원하는 번호의 좌석 현황
	void resSeat(unsigned short num, string name); // 예약
	void cancelSeat(unsigned short num, string name); // 예약 취소
};

class AirlineBook {
	Schedule* sc;
public:
	AirlineBook() { this->sc = new Schedule[3]{ Schedule("07"), Schedule("12"), Schedule("17") }; } // 생성자
	virtual ~AirlineBook() { delete[] sc; } // 가상 소멸자

	void start();
};