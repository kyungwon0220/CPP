// string 클래스를 이용하여 빈칸을 포함하는 문자열을 입력받고 문자열에서 'a'가 몇개 있는지 출력하는 프로그램을 작성해보자.
// (1) 문자열에서 'a'를 찾기 위해 string 클래스의 멤버 at()나 []를 이용하여 작성 하라.
// (2) 문자열에서 'a'를 찾기 위해 string 클래스의 find() 멤버 함수를 이용하여 작성 하라.
// text.find('a', 'index');는 text 문자열의 index 위치부터 'a'를 찾아 문자열 내 인덱스를 리턴한다.


#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	unsigned int count = 0;
	
	cout << "문자열 입력>>";
	getline(cin, str, '\n');

	//for (unsigned short i = 0; i < a.length(); i++) if (a.at(i) == 'a') count++;

	short index = 0;
	while (str.find('a', index) != -1) {
		count++;
		index = str.find('a', index) + 1;
	}
	
	cout << "문자 a는 " << count << "개 있습니다.";
}