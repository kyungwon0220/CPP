#include <iostream>
#include <string>

using namespace std;

class Product { // ��ǰ
	static unsigned short id; // �ĺ���
	string expl; // ��ǰ ����
	string maker; // ������
	unsigned short price; //����
public:
	unsigned short getId() { return this->id; }
	string getExpl() { return this->expl; }
	string getMaker() { return this->maker; }
	unsigned short getPrice() { return this->price; }

	Product(string expl, string maker, unsigned short price); // ������

	virtual void show() = 0; // ���� ���� �Լ�
};

class Book : public Product { // å
	unsigned short ISBN;
	string book_author; // ����
	string book_title; // å ����
public:
	unsigned short getISBN() { return this->ISBN; }
	string getBook_author() { return this->book_author; }
	string getBook_title() { return this->book_title; }

	Book(string expl, string maker, unsigned short price, string book_title, string book_author, unsigned short ISBN); // ������

	void show();
};

class CompactDisc : public Product { // ����CD
	string song_title; // �ٹ� ����
	string song_author; // ���� �̸�
public:
	string getSong_title() { return this->song_title; }
	string getSong_author() { return this->song_author; }

	CompactDisc(string expl, string maker, unsigned short price, string song_title, string sont_author); // ������

	void show();
};

class ConversationBook : public Book { //ȸȭå
	string len_info; // ��� �� ����
 public:
	 string getLen_info() { return this->len_info; }

	ConversationBook(string expl, string maker, unsigned short price, string book_title, string book_author, unsigned short ISBN, string len_info); // ������
 
	void show();
};