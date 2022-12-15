#include "�ǽ�����9.h"

unsigned short console::selectMenu() {
	cout << "����:1, ���:2, ����:3, ������:4>>";
	unsigned short sel;
	cin >> sel;
	return sel;
}

unsigned short console::selectTime() {
	cout << "07��:1, 12��:2, 17��:3>> ";
	unsigned short sel;
	cin >> sel;
	return sel;
}

unsigned short console::selectSeatNum() {
		cout << "�¼� ��ȣ>> ";
		unsigned short num;
		cin >> num;
		return num;
}

string console::userName() {
	cout << "�̸� �Է�>> ";
	string name;
	cin >> name;
	return name;
}


void Seat::setSeat(string name) { this->name = name; this->check = false; } // ����

void Seat::resetSeat() { this->name = "---"; this->check = true; } // ���� ��ҽ�


void Schedule::show() { // ����
	cout << this->scName << "��:\t";
	for (unsigned short i = 0; i < 8; i++) cout << " " << seat[i].getName() << "\t";
	cout << endl;
}

void Schedule::resSeat(unsigned short num, string name) { this->seat[num].setSeat(name); } // ����

void Schedule::cancelSeat(unsigned short num, string name) { // ���� ���
	if (name.compare(this->seat[num].getName()) == 0) this->seat[num].resetSeat();
	else cout << "�����ڸ�� ����ġ�Ͽ�, ���� ��� �Ұ�" << endl;
}

void AirlineBook::start() {
	bool exit = true;

	while (exit) {
		unsigned short menu = console::selectMenu(); // ����ڷκ��� �޴� ����

		if (menu == 1 || menu == 2) {
			unsigned short time = console::selectTime() - 1; // ���� �ð�

			switch (time) {
			case 0:
			case 1:
			case 2:
			{
				sc[time].show();

				unsigned short num = console::selectSeatNum() - 1; // �¼� ��ȣ
				string name = console::userName(); // ����� �̸�

				if (menu == 1 && sc[time].checkSeat(num)) { // ������ ���ϴ� �¼� ��ȣ�� ����ִٸ�
					sc[time].resSeat(num, name);
				}
				else if (menu == 1 && (sc[time].checkSeat(num) == false)) {
					cout << "�̹� ����� �¼�����, ���� �Ұ�" << endl;
					break;
				}
				else if (menu == 2 && (sc[time].checkSeat(num) == false)) {
					sc[time].cancelSeat(num, name);
				}
				else if (menu == 2 && sc[time].checkSeat(num)) {
					cout << "��������, ���� ��� �Ұ�" << endl;
					break;
				}
				break;
			} // case end
			default:
				break;
			} // switch end
		}
		else if (menu == 3) { // ����� �¼� ��Ȳ
			sc[0].show();
			sc[1].show();
			sc[2].show();
		}
		else { // ������
			cout << "���� �ý����� �����մϴ�.";
			exit = false;
			break;
		}
	} // while end
} // void start() end