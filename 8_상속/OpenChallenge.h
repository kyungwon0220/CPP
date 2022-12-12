#include <iostream>
#include <string>

using namespace std;

class Product { // 상품
	static unsigned short id; // 식별자
	string expl; // 상품 설명
	string maker; // 생산자
	unsigned short price; //가격
public:
	unsigned short getId() { return this->id; }
	string getExpl() { return this->expl; }
	string getMaker() { return this->maker; }
	unsigned short getPrice() { return this->price; }

	Product(string expl, string maker, unsigned short price); // 생성자

	virtual void show() = 0; // 순수 가상 함수
};

class Book : public Product { // 책
	unsigned short ISBN;
	string book_author; // 저자
	string book_title; // 책 제목
public:
	unsigned short getISBN() { return this->ISBN; }
	string getBook_author() { return this->book_author; }
	string getBook_title() { return this->book_title; }

	Book(string expl, string maker, unsigned short price, string book_title, string book_author, unsigned short ISBN); // 생성자

	void show();
};

class CompactDisc : public Product { // 음악CD
	string song_title; // 앨범 제목
	string song_author; // 가수 이름
public:
	string getSong_title() { return this->song_title; }
	string getSong_author() { return this->song_author; }

	CompactDisc(string expl, string maker, unsigned short price, string song_title, string sont_author); // 생성자

	void show();
};

class ConversationBook : public Book { //회화책
	string len_info; // 언어 명 정보
 public:
	 string getLen_info() { return this->len_info; }

	ConversationBook(string expl, string maker, unsigned short price, string book_title, string book_author, unsigned short ISBN, string len_info); // 생성자
 
	void show();
};