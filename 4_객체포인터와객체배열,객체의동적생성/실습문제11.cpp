// ������ Ŀ�����Ǳ�� �۵��ϴ� ���α׷��� ����� ���� �ʿ��� �� Ŭ�����̴�.
// ������ ���� ����ǵ��� main() �Լ��� CoffeeVendingMachine, Container�� �ϼ��϶�.
// ���� Ŀ��, ��, ���� �� �ܷ��� �ϳ��� ������ Ŀ�Ǹ� ������ �� ���� ��� '���ᰡ �����մϴ�.'�� ����϶�.


#include <iostream>

using namespace std;

class Container { // �� �ϳ��� ��Ÿ���� Ŭ����
	int size; // ���� ���� ��, �ִ� ���差�� 10
public:
	Container() { size = 10; }
	void fill() { this->size = 10; } // �ִ뷮(10)���� ä���
	void consume() { this->size -= 1; } // 1 ��ŭ �Ҹ��ϱ�
	int getSize() { return this->size; } // ���� ũ�� ����
};


class CoffeeVendingMachine { // Ŀ�����Ǳ⸦ ǥ���ϴ� Ŭ����
	Container tong[3]; // tong[0]�� Ŀ��, tong[1]�� ��, tong[2]�� �������� ��Ÿ��

	void fill() { for (unsigned short i = 0; i < 3; i++) tong[i].fill(); } // 3���� ���� ��� 10���� ä��

	void selectEspresso() { tong[0].consume(); tong[1].consume(); } // ���������Ҹ� ������ ���, Ŀ�� 1, �� 1 �Ҹ�
	void selectAmericano() { tong[0].consume(); tong[1].consume(); tong[1].consume(); } // �Ƹ޸�ī�븦 ������ ���, Ŀ�� 1, �� 2 �Ҹ�
	void selectSugarCoffee() { tong[0].consume(); tong[1].consume(); tong[1].consume(); tong[2].consume(); } // ����Ŀ�Ǹ� ������ ���, Ŀ��1, �� 2 �Ҹ�, ���� 1 �Ҹ�

	void show() { cout << "Ŀ�� " << tong[0].getSize() << ", �� " << tong[1].getSize() << ", ���� " << tong[2].getSize() << endl; } // ���� Ŀ��, ��, ������ �ܷ� ���

	unsigned short tongCheck(const unsigned short *selectNum) { // ���� ������ return 1;
		switch (*selectNum) {
		case 1: // ���������� ���� üũ
			if (this->tong[0].getSize() < 1 || this->tong[1].getSize() < 1) {
				cout << "���ᰡ �����մϴ�." << endl;
				return 1;
			}
			else return 0;
			break;
		case 2: // �Ƹ޸�ī�� ���� üũ
			if (this->tong[0].getSize() < 1 || this->tong[1].getSize() < 2) {
				cout << "���ᰡ �����մϴ�." << endl;
				return 1;
			}
			else return 0;
			break;
		case 3: // ����Ŀ�� ���� üũ
			if (this->tong[0].getSize() < 1 || this->tong[1].getSize() < 2 || this->tong[2].getSize() < 1) {
				cout << "���ᰡ �����մϴ�." << endl;
				return 1;
			}
			else return 0;
			break;
		}
	}
public:
	void run() { // Ŀ�� ���Ǳ� �۵�

		unsigned short selectNum;


		cout << "�޴��� �����ּ���(1:����������, 2:�Ƹ޸�ī��, 3:����Ŀ��, 4:�ܷ�����, 5:ä���)>>";

		cin >> selectNum;

		switch (selectNum) {
		case 1:
			if (tongCheck(&selectNum)) break; // ���� ������ switch�� break;
			selectEspresso();
			cout << "���������� �弼��" << endl;
			break;
		case 2:
			if (tongCheck(&selectNum)) break; // ���� ������ switch�� break;
			selectAmericano();
			cout << "�Ƹ޸�ī�� �弼��" << endl;
			break;
		case 3:
			if (tongCheck(&selectNum)) break; // ���� ������ switch�� break;
			selectSugarCoffee();
			cout << "����Ŀ�� �弼��" << endl;
			break;
		case 4:
			show();
			break;
		case 5:
			fill();
			show();
			break;
		}
	}

	~CoffeeVendingMachine() {}
};


int main() {
	CoffeeVendingMachine tester;
	
	cout << "***** Ŀ�����Ǳ⸦ �۵��մϴ�. *****" << endl;
	
	do {		
		tester.run();
	} while (1);
}