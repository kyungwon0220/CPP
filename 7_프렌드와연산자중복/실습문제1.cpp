// 문제 1~4까지 사용될 Book 클래스는 다음과 같다.
// Book 객체에 대해 다음 연산을 하고자 한다.
// (1) +=, -= 연산자 함수를 Book 클래스의 멤버 함수로 구현하라.
// (2) +=, -= 연산자 함수를 Book 클래스 외부 함수로 구현하라.

#include <iostream>

using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) { this->title = title; this->price = price; this->pages = pages; }
	void show() { cout << title << ' ' << price << "원 " << pages << " 페이지" << endl; }
	string getTitle() { return title; }

	Book& operator+=(int price) { this->price += price; return *this; } // friend Book& operator +=(Book& book, int price);
	Book& operator-=(int price) { this->price -= price; return *this; } // friend Book& operator -=(Book& book, int price);
};

// Book& operator+=(Book& b, int price) { b.price += price; return b; }
// Book& operator-=(Book& b, int price) { b.price -= price; return b; }

int main() {
	Book a("청춘", 20000, 300), b("미래", 30000, 500);
	a += 500; // 책 a의 가격 500원 증가
	b -= 500; // 책 b의 가격  500원 감소
	a.show();
	b.show();
}