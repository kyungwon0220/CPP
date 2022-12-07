// ���� 1~4���� ���� Book Ŭ������ ������ ����.
// ���� ������ ���� å�� ������ ���� ������ ���ϰ��� �Ѵ�. < �����ڸ� �ۼ��϶�.

#include <iostream>

using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) { this->title = title; this->price = price; this->pages = pages; }
	void show() { cout << title << ' ' << price << "�� " << pages << " ������" << endl; }
	string getTitle() { return title; }

	friend bool operator<(string s, Book& b);
};

bool operator<(string s, Book& b) { if (b.title > s) return true; else return false; }

int main() {
	Book a("û��", 20000, 300);
	string b;
	cout << "å �̸��� �Է��ϼ���>>";
	getline(cin, b); // Ű����κ��� ���ڿ��� å �̸��� �Է� ����
	if (b < a) cout << a.getTitle() << "�� " << b << "���� �ڿ� �ֱ���!" << endl;
}