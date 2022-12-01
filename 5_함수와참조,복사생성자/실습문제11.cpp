// 책의 이름과 가격을 저장하는 다음 Book 클래스에 대해 물음에 답하여라.
// (1)Book 클래스의 생성자, 소멸자, set() 함수를 작성하라.
// set() 함수는 멤버 변수 title에 할당된 메모리가 있으면 먼저 반환한다.
// 그러고 나서 새로운 메모리를 할당받고 이곳에 매개 변수로 전달받은 책이름을 저장한다.
// (2) 컴파일러가 삽입하는 디폴트 복사 생성자 코드는 무엇인가?
// (3)디폴트 복사 생성자만 있을 때 아래 main() 함수는 실행 오류가 발생한다.
// 다음과 같이 실행 오류가 발생하지 않도록 깊은 복사 생성자를 작성하라.
// (4) 문제 (3)에서 실행 오류가 발생하는 원인은 Book 클래스에서 C-스트링(char* title) 방식으로 문자열을 다루었기 때문이다.
// 복사 생성자를 작성하지 말고 문자열을 string 클래스를 사용하여, 문제 (3)의 실행 오류가 발생하지 않도록 Book 클래스를 수정하라.
// 이 문제를 풀고 나면 문자열을 다룰 때, string을 사용해야하는 이유를 명확히 알게 될 것이다.


#define _CRT_SECURE_NO_WARNINGS // 비주얼 스튜디오에서 stpcpy() 때문에 발생하는 컴파일 오류를 막기 위해

#include <iostream>

using namespace std;

class Book {
	char* title; // 제목 문자열
	int price; // 가격
public:
	Book(const char* title, int price) { // (1) 정답
		unsigned short len = strlen(title);

		this->title = (char*)malloc(sizeof(char) * len + 1);
		strcpy(this->title, title);
		this->price = price;
	}

	~Book() { if (title) free(this->title); } // (1) 정답

	/*
	Book::Book(Book& b) { // (2) 정답. 디폴트 복사 생성자
		title = b.title;
		price = b.price;
	}
	*/

	Book(Book& b) { // (3) 정답. 깊은 복사 복사 생성자 작성
		unsigned short len = strlen(b.title);

		this->title = new char[len + 1];
		strcpy(this->title, b.title);
		this->price = b.price;
	}

	void set(string title, int price) { // (1) 정답
		unsigned short len = title.length();
		
		if (this->title) // 현재 객체에 title에 메모리가 할당되어 책 이름이 적혀있는 상황
			delete[] this->title; // 현재 title에 할당된 메모리 반환

		this->title = new char[len + 1]; // 새로 메모리 할당

		const char* tmp = title.c_str();
		strcpy(this->title, tmp);

		this->price = price;
	}

	void show() { cout << title << ' ' << price << "원" << endl; }
};

int main() {
	Book cpp("명품C++", 10000);
	Book java = cpp; // 복사 생성자 호출됨
	java.set("명품자바", 12000);
	cpp.show();
	java.show();
}