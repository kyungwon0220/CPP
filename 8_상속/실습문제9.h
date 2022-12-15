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
	string name; // ������ �̸�
	bool check; // ����� ���� == false
public:
	Seat() { this->name = "---"; this->check = true; } // ������
	void setSeat(string name); // ����
	void resetSeat(); // ���� ��ҽ�, ��������

	string getName() { return this->name; }
	bool seatStat() { return this->check; } // ���� ��Ȳ
};


class Schedule { // ������
	string scName;
	Seat* seat;
public:
	Schedule(string scName) { this->seat = new Seat[8]; /* 8���� �¼� */ this->scName = scName; } // ������
	virtual ~Schedule() { delete[] seat; } // ���� �Ҹ���

	void show();
	bool checkSeat(unsigned short num) { return seat[num].seatStat(); } // ���ϴ� ��ȣ�� �¼� ��Ȳ
	void resSeat(unsigned short num, string name); // ����
	void cancelSeat(unsigned short num, string name); // ���� ���
};

class AirlineBook {
	Schedule* sc;
public:
	AirlineBook() { this->sc = new Schedule[3]{ Schedule("07"), Schedule("12"), Schedule("17") }; } // ������
	virtual ~AirlineBook() { delete[] sc; } // ���� �Ҹ���

	void start();
};