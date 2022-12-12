#include "OpenChallenge.h"

Product::Product(string expl, string maker, unsigned short price) {
	this->expl = expl;
	this->maker = maker;
	this->price = price;
}


Book::Book(string expl, string maker, unsigned short price, string book_title, string book_author, unsigned short ISBN) : Product(expl, maker, price) {
	this->book_title = book_title;
	this->book_author = book_author;
	this->ISBN = ISBN;
}

void Book::show() {
	cout << "��ǰ����>>" << this->getExpl() << endl;
	cout << "������>>" << this->getMaker() << endl;
	cout << "����>>" << this->getPrice() << endl;
	cout << "å����>>" << this->getBook_title() << endl;
	cout << "����>>" << this->getBook_author() << endl;
	cout << "ISBN>>" << this->getISBN() << endl << endl;
}


CompactDisc::CompactDisc(string expl, string maker, unsigned short price, string song_title, string sont_author) : Product(expl, maker, price) {
	this->song_title = song_title;
	this->song_author = sont_author;
}

void CompactDisc::show() {
	cout << "��ǰ����>>" << this->getExpl() << endl;
	cout << "������>>" << this->getMaker() << endl;
	cout << "����>>" << this->getPrice() << endl;
	cout << "�ٹ�����>>" << this->getSong_title() << endl;
	cout << "����>>" << this->getSong_author() << endl << endl;
}


ConversationBook::ConversationBook(string expl, string maker, unsigned short price, string book_title, string book_author, unsigned short ISBN, string len_info) : Book(expl, maker, price, book_title, book_author, ISBN) {
	this->len_info = len_info;
}

void ConversationBook::show() {
	cout << "��ǰ����>>" << this->getExpl() << endl;
	cout << "������>>" << this->getMaker() << endl;
	cout << "����>>" << this->getPrice() << endl;
	cout << "ISBN>>" << this->getISBN() << endl;
	cout << "å����>>" << this->getBook_title() << endl;
	cout << "����>>" << this->getBook_author() << endl;
	cout << "���>>" << this->getLen_info() << endl << endl;
}