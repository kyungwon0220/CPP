// å�� �̸��� ������ �����ϴ� ���� Book Ŭ������ ���� ������ ���Ͽ���.
// (1)Book Ŭ������ ������, �Ҹ���, set() �Լ��� �ۼ��϶�.
// set() �Լ��� ��� ���� title�� �Ҵ�� �޸𸮰� ������ ���� ��ȯ�Ѵ�.
// �׷��� ���� ���ο� �޸𸮸� �Ҵ�ް� �̰��� �Ű� ������ ���޹��� å�̸��� �����Ѵ�.
// (2) �����Ϸ��� �����ϴ� ����Ʈ ���� ������ �ڵ�� �����ΰ�?
// (3)����Ʈ ���� �����ڸ� ���� �� �Ʒ� main() �Լ��� ���� ������ �߻��Ѵ�.
// ������ ���� ���� ������ �߻����� �ʵ��� ���� ���� �����ڸ� �ۼ��϶�.
// (4) ���� (3)���� ���� ������ �߻��ϴ� ������ Book Ŭ�������� C-��Ʈ��(char* title) ������� ���ڿ��� �ٷ���� �����̴�.
// ���� �����ڸ� �ۼ����� ���� ���ڿ��� string Ŭ������ ����Ͽ�, ���� (3)�� ���� ������ �߻����� �ʵ��� Book Ŭ������ �����϶�.
// �� ������ Ǯ�� ���� ���ڿ��� �ٷ� ��, string�� ����ؾ��ϴ� ������ ��Ȯ�� �˰� �� ���̴�.


#define _CRT_SECURE_NO_WARNINGS // ���־� ��Ʃ������� stpcpy() ������ �߻��ϴ� ������ ������ ���� ����

#include <iostream>

using namespace std;

class Book {
	char* title; // ���� ���ڿ�
	int price; // ����
public:
	Book(const char* title, int price) { // (1) ����
		unsigned short len = strlen(title);

		this->title = (char*)malloc(sizeof(char) * len + 1);
		strcpy(this->title, title);
		this->price = price;
	}

	~Book() { if (title) free(this->title); } // (1) ����

	/*
	Book::Book(Book& b) { // (2) ����. ����Ʈ ���� ������
		title = b.title;
		price = b.price;
	}
	*/

	Book(Book& b) { // (3) ����. ���� ���� ���� ������ �ۼ�
		unsigned short len = strlen(b.title);

		this->title = new char[len + 1];
		strcpy(this->title, b.title);
		this->price = b.price;
	}

	void set(string title, int price) { // (1) ����
		unsigned short len = title.length();
		
		if (this->title) // ���� ��ü�� title�� �޸𸮰� �Ҵ�Ǿ� å �̸��� �����ִ� ��Ȳ
			delete[] this->title; // ���� title�� �Ҵ�� �޸� ��ȯ

		this->title = new char[len + 1]; // ���� �޸� �Ҵ�

		const char* tmp = title.c_str();
		strcpy(this->title, tmp);

		this->price = price;
	}

	void show() { cout << title << ' ' << price << "��" << endl; }
};

int main() {
	Book cpp("��ǰC++", 10000);
	Book java = cpp; // ���� ������ ȣ���
	java.set("��ǰ�ڹ�", 12000);
	cpp.show();
	java.show();
}