// string 클래스를 이용하여 빈칸을 포함하는 문자열을 입력받고 문자열에서 'a'가 몇개 있는지 출력하는 프로그램을 작성해보자.

#include <iostream>
#include <string>

using namespace std;

int main() {
	string a;
	unsigned int count = 0;
	
	cout << "문자열 입력>>";
	getline(cin, a, '\n');

	//for (unsigned short i = 0; i < a.length(); i++) if (a.at(i) == 'a') count++;

	short index = 0;
	while (a.find('a', index) != -1) {
		count++;
		index = a.find('a', index) + 1;
	}
	
	cout << "문자 a는 " << count << "개 있습니다.";
}