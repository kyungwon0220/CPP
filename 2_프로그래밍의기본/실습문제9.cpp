// 이름, 주소, 나이를 입력받아 다시 출력하는 프로그램을 작성하라. 실행 예시는 다음과 같다.
// 목적 : 빈칸을 포함하는 문자열 읽기

#include <iostream>
#include <string>

using namespace std;

int main() {
	string name;
	string address;
	string age;

	cout << "이름은?";
	getline(cin, name);

	cout << "주소는?";
	getline(cin, address);

	cout << "나이는?";
	getline(cin, age);

	cout << name << ", " << address << ", " << age << "세";
}