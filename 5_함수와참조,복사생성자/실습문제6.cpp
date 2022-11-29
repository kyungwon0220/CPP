// find() 함수의 원형은 다음과 같다.
// 문자열 a에서 문자 c를 찾아, 문자 c가 있는 공간에 대한 참조를 리턴한다.
// 만일 문자 c를 찾을 수 없다면 success 참조 매개 변수에 false를 설정한다.
// 물론 찾게 되면 success에 true를 설정한다.
// 다음 main()이 잘 실행되도록 find()를 작성하라.


#include <iostream>

using namespace std;

char& find(char a[], char c, bool& success) {
	unsigned short len = strlen(a);

	for (unsigned short i = 0; i < len; i++) {
		if (a[i] == c) {
			success = true;
			return a[i];
		}
	}

	success = false;
}

int main() {
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);
	if (b == false) {
		cout << "M을 발견할 수 없다" << endl;
		return 0;
	}
	loc = 'a'; // 'M' 위치에 'm' 기록
	cout << s << endl; // "mike"가 출력됨
}