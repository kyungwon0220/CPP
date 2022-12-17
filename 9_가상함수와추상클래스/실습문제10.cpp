#include "실습문제10.h"

unsigned short UI::selMenu() {
	unsigned short sel;

	cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
	cin >> sel;
	return sel;
}

unsigned short UI::selShape() {
	unsigned short sel;
	
	cout << "선:1, 원:2, 사각형:3 >> ";
	cin >> sel;
	return sel;
}


void GraphicEditor::start() {
	bool exit = true;

	do {
		unsigned short menu = UI::selMenu();
	
		switch (menu) {
		case 1: {
			unsigned short shape = UI::selShape();

			if (this->count == 0) {
				if (shape == 1) this->pStart = new Line();
				else if (shape == 2) this->pStart = new Circle();
				else if (shape == 3) this->pStart = new Rect();

				this->pLast = this->pStart;
			}
			else {
				if (shape == 1) this->pLast = this->pLast->add(new Line());
				else if (shape == 2) this->pLast = this->pLast->add(new Circle());
				else if (shape == 3) this->pLast = this->pLast->add(new Rect());
			}

			count++;
			break;
		}
		case 2:
		{
			unsigned short index;

			cout << "삭제하고자 하는 도형의 인덱스 >> ";
			cin >> index;

			if(index >= this->count) cout << "인덱스를 잘못 입력하셨습니다." << endl;
			else {
				Shape* tmp = this->pStart;
				Shape* deltmp = this->pStart;

				for (unsigned short i = 0; i < index; i++) {
					deltmp = tmp; // 삭제하고자 하는 인덱스 -1 포인터
					tmp = tmp->getNext(); // 삭제하고자 하는 인덱스 포인터
				}

				if (index == 0) this->pStart = tmp->getNext(); // 삭제하고자 하는 인덱스가 최초 인덱스일 경우
				else deltmp->setNext(tmp);

				this->count--;

				if (this->count == 1) this->pLast = this->pStart;
			}
			
			break;
		}
		case 3:
		{
			Shape* tmp = this->pStart;
			for (unsigned short i = 0; i < this->count; i++) {				
				cout << i << ": ";
				tmp->draw();

				tmp = tmp->getNext();
			}
			break;
		}			
		default:
			exit = false;
			break;
		}
	} while (exit);
}