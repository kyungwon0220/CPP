// ���� 1~4���� ���� Book Ŭ������ ������ ����.
// Book ��ü�� Ȱ���ϴ� ����̴�.
// (1) �� ���� == ������ �Լ��� ���� Book Ŭ������ �ۼ��϶�.
// (2) �� ���� == �����ڸ� ������ �Լ��� �ۼ��϶�.

#include <iostream>

using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) { this->title = title; this->price = price; this->pages = pages; }
	void show() { cout << title << ' ' << price << "�� " << pages << " ������" << endl; }
	string getTitle() { return title; }

	bool operator==(int price) { if(this->price == price) return true; else return false; }
	bool operator==(string title) { if (this->title.compare(title) == 0) return true; else return false; }
	bool operator==(const Book& b) {
		if (this->title.compare(b.title) == 0 && this->price == b.price && this->pages == b.pages) return true; else return false;
	}
};

int main() {
	Book a("��ǰ C++", 30000, 500), b("��ǰ C++", 30000, 500);
	if (a == 30000) cout << "���� 30000��" << endl; // price ��
	if (a == "��ǰ C++") cout << "��ǰ C++ �Դϴ�." << endl; // å title ��
	if (a == b) cout << "�� å�� ���� å�Դϴ�." << endl; // title, price, pages ��� ��
}