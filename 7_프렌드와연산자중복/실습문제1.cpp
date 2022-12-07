// ���� 1~4���� ���� Book Ŭ������ ������ ����.
// Book ��ü�� ���� ���� ������ �ϰ��� �Ѵ�.
// (1) +=, -= ������ �Լ��� Book Ŭ������ ��� �Լ��� �����϶�.
// (2) +=, -= ������ �Լ��� Book Ŭ���� �ܺ� �Լ��� �����϶�.

#include <iostream>

using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) { this->title = title; this->price = price; this->pages = pages; }
	void show() { cout << title << ' ' << price << "�� " << pages << " ������" << endl; }
	string getTitle() { return title; }

	Book& operator+=(int price) { this->price += price; return *this; } // friend Book& operator +=(Book& book, int price);
	Book& operator-=(int price) { this->price -= price; return *this; } // friend Book& operator -=(Book& book, int price);
};

// Book& operator+=(Book& b, int price) { b.price += price; return b; }
// Book& operator-=(Book& b, int price) { b.price -= price; return b; }

int main() {
	Book a("û��", 20000, 300), b("�̷�", 30000, 500);
	a += 500; // å a�� ���� 500�� ����
	b -= 500; // å b�� ����  500�� ����
	a.show();
	b.show();
}