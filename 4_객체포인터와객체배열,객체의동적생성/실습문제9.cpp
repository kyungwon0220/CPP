// 실습 문제 7의 문제를 수정해보자.
// 다음과 같은 Person 클래스가 있다.
// Person 클래스와 main() 함수를 작성하여, 3개의 Person 객체를 가지는 배열을 선언하고, 다음과 같이 키보드에서 이름과 전화번호를 입력받아 출력하고 검색하는 프로그램을 완성하라.


#include <iostream>
#include <string>

using namespace std;

class Person {
	string name;
	string tel;
public:
	Person() {}
	string getName() { return this->name; }
	string getTel() { return this->tel; }
	void set(string name, string tel) { this->name = name; this->tel = tel; }
};


int main() {
	string s;
	Person* p = new Person[3];
	int findex;
	string name, tel, searchN;


	cout << "이름과 전화 번호를 입력해 주세요" << endl;

	for(unsigned short i=0; i<3; i++) {
		cout << "사람 " << i + 1 << ">> ";
		getline(cin, s, '\n');

		findex = s.find(' ', 0); // 공백자 인덱스

		name = s.substr(0, findex);
		tel = s.substr(findex+1, s.length());

		p[i].set(name, tel);
	}


	cout << "모든 사람의 이름은 ";

	for (unsigned short i = 0; i < 3; i++) cout << p[i].getName() << ' ';
	
	cout << "\n전화번호 검색합니다. 이름을 입력하세요>>";

	cin >> searchN;

	for (unsigned short i = 0; i < 3; i++) {
		string tmpName = p[i].getName();

		if (tmpName == searchN) {
			cout << "전화 번호는 " << p[i].getTel() << endl;
			break;
		}
	}

	delete[] p;
}