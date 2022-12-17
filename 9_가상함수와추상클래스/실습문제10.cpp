#include "�ǽ�����10.h"

unsigned short UI::selMenu() {
	unsigned short sel;

	cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
	cin >> sel;
	return sel;
}

unsigned short UI::selShape() {
	unsigned short sel;
	
	cout << "��:1, ��:2, �簢��:3 >> ";
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

			cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
			cin >> index;

			if(index >= this->count) cout << "�ε����� �߸� �Է��ϼ̽��ϴ�." << endl;
			else {
				Shape* tmp = this->pStart;
				Shape* deltmp = this->pStart;

				for (unsigned short i = 0; i < index; i++) {
					deltmp = tmp; // �����ϰ��� �ϴ� �ε��� -1 ������
					tmp = tmp->getNext(); // �����ϰ��� �ϴ� �ε��� ������
				}

				if (index == 0) this->pStart = tmp->getNext(); // �����ϰ��� �ϴ� �ε����� ���� �ε����� ���
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