// 문제 1~4까지 사용될 Book 클래스는 다음과 같다.
// Book 객체를 활용하는 사례이다.
// (1) 세 개의 == 연산자 함수를 가진 Book 클래스를 작성하라.
// (2) 세 개의 == 연산자를 프렌드 함수로 작성하라.

#include <iostream>

using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) { this->title = title; this->price = price; this->pages = pages; }
	void show() { cout << title << ' ' << price << "원 " << pages << " 페이지" << endl; }
	string getTitle() { return title; }

	bool operator==(int price) { if(this->price == price) return true; else return false; }
	bool operator==(string title) { if (this->title.compare(title) == 0) return true; else return false; }
	bool operator==(const Book& b) {
		if (this->title.compare(b.title) == 0 && this->price == b.price && this->pages == b.pages) return true; else return false;
	}
};

int main() {
	Book a("명품 C++", 30000, 500), b("고품 C++", 30000, 500);
	if (a == 30000) cout << "정가 30000원" << endl; // price 비교
	if (a == "명품 C++") cout << "명품 C++ 입니다." << endl; // 책 title 비교
	if (a == b) cout << "두 책이 같은 책입니다." << endl; // title, price, pages 모두 비교
}