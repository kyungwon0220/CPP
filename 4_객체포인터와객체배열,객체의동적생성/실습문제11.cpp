// 다음은 커피자판기로 작동하는 프로그램을 만들기 위해 필요한 두 클래스이다.
// 다음과 같이 실행되도록 main() 함수와 CoffeeVendingMachine, Container를 완성하라.
// 만일 커피, 물, 설탕 중 잔량이 하나라도 부족해 커피를 제공할 수 없는 경우 '원료가 부족합니다.'를 출력하라.


#include <iostream>

using namespace std;

class Container { // 통 하나를 나타내는 클래스
	int size; // 현재 저장 량, 최대 저장량은 10
public:
	Container() { size = 10; }
	void fill() { this->size = 10; } // 최대량(10)으로 채우기
	void consume() { this->size -= 1; } // 1 만큼 소모하기
	int getSize() { return this->size; } // 현재 크기 리턴
};


class CoffeeVendingMachine { // 커피자판기를 표현하는 클래스
	Container tong[3]; // tong[0]는 커피, tong[1]은 물, tong[2]는 설탕통을 나타냄

	void fill() { for (unsigned short i = 0; i < 3; i++) tong[i].fill(); } // 3개의 통을 모두 10으로 채움

	void selectEspresso() { tong[0].consume(); tong[1].consume(); } // 에스프레소를 선택한 경우, 커피 1, 물 1 소모
	void selectAmericano() { tong[0].consume(); tong[1].consume(); tong[1].consume(); } // 아메리카노를 선택한 경우, 커피 1, 물 2 소모
	void selectSugarCoffee() { tong[0].consume(); tong[1].consume(); tong[1].consume(); tong[2].consume(); } // 설탕커피를 선택한 경우, 커피1, 물 2 소모, 설탕 1 소모

	void show() { cout << "커피 " << tong[0].getSize() << ", 물 " << tong[1].getSize() << ", 설탕 " << tong[2].getSize() << endl; } // 현재 커피, 물, 설탕의 잔량 출력

	unsigned short tongCheck(const unsigned short *selectNum) { // 원료 부족시 return 1;
		switch (*selectNum) {
		case 1: // 에스프레소 원료 체크
			if (this->tong[0].getSize() < 1 || this->tong[1].getSize() < 1) {
				cout << "원료가 부족합니다." << endl;
				return 1;
			}
			else return 0;
			break;
		case 2: // 아메리카노 원료 체크
			if (this->tong[0].getSize() < 1 || this->tong[1].getSize() < 2) {
				cout << "원료가 부족합니다." << endl;
				return 1;
			}
			else return 0;
			break;
		case 3: // 설탕커피 원료 체크
			if (this->tong[0].getSize() < 1 || this->tong[1].getSize() < 2 || this->tong[2].getSize() < 1) {
				cout << "원료가 부족합니다." << endl;
				return 1;
			}
			else return 0;
			break;
		}
	}
public:
	void run() { // 커피 자판기 작동

		unsigned short selectNum;


		cout << "메뉴를 눌러주세요(1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기)>>";

		cin >> selectNum;

		switch (selectNum) {
		case 1:
			if (tongCheck(&selectNum)) break; // 원료 부족시 switch문 break;
			selectEspresso();
			cout << "에스프레소 드세요" << endl;
			break;
		case 2:
			if (tongCheck(&selectNum)) break; // 원료 부족시 switch문 break;
			selectAmericano();
			cout << "아메리카노 드세요" << endl;
			break;
		case 3:
			if (tongCheck(&selectNum)) break; // 원료 부족시 switch문 break;
			selectSugarCoffee();
			cout << "설탕커피 드세요" << endl;
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
	
	cout << "***** 커피자판기를 작동합니다. *****" << endl;
	
	do {		
		tester.run();
	} while (1);
}