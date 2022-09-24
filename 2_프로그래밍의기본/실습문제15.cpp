// 덧셈(+), 뺄셈(-), 곱셈(*), 나눗셈(/), 나머지(%)의 정수 5칙 연산을 할 수 있는 프로그램을 작성하라.
// 식은 다음과 같은 형식으로 입력된다.
// 정수와 연산자는 하나의 빈칸으로 분리된다.
// 목적 : 공백을 포함하는 문자열 읽기. C++ 프로그램 종합 응용
// 한 줄을 문자열로 읽고, 공백 문자를 찾아 연산자와 두 개의 피연산자를 구분한 후, 계산하면 된다. 문자열을 정수로 바꿀때 atoi() 함수를 이용하면 된다. 예를 들면 atoi("34") = 34

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#ifndef _CRT_SECURE_NO_WARNINGS
	#include <string>
#endif // !_CRT_SECURE_NO_WARNINGS




using namespace std;

int main() {
#ifndef _CRT_SECURE_NO_WARNINGS
	while(1) { // string 사용 풀이
		string s;
		string a, b, c;

		unsigned long check1, check2;


		cout << "? ";
		getline(cin, s);

		check1 = s.find(' ', 0);// s 中 첫 ' ' 공백자 인덱스 위치 == check1;
		a = s.substr(0, check1); // check1 인덱스까지의 문자열 == a;

		b = s[check1 + 1]; // 정수와 연산자는 하나의 빈 칸으로 분리되기 때문에, +1
		c = s.substr(check1 + (int)3, s.length());

		if(b.compare("+") == 0) cout << a << " " << b << " " << c << " = " << stoi(a) + stoi(c) << endl;
		else if (b.compare("-") == 0) cout << a << " " << b << " " << c << " = " << stoi(a) - stoi(c) << endl;
		else if (b.compare("*") == 0) cout << a << " " << b << " " << c << " = " << stoi(a) * stoi(c) << endl;
		else if (b.compare("/") == 0) cout << a << " " << b << " " << c << " = " << stoi(a) / stoi(c) << endl;
		else if (b.compare("%") == 0) cout << a << " " << b << " " << c << " = " << stoi(a) % stoi(c) << endl;
	}
#endif // !_CRT_SECURE_NO_WARNINGS
	

#ifdef _CRT_SECURE_NO_WARNINGS
	while (1) { // string 미사용 풀이
		char s[100];
		char *a, *b, *c;

		cout << "? ";
		cin.getline(s, 100);

		a = strtok(s, " ");
		b = strtok(NULL, " ");
		c = strtok(NULL, " ");

		if(strcmp(b, "+") == 0) cout << a << " " << b << " " << c << " = " << atoi(a) + atoi(c) << endl;
		else if (strcmp(b, "-") == 0) cout << a << " " << b << " " << c << " = " << atoi(a) - atoi(c) << endl;
		else if (strcmp(b, "*") == 0) cout << a << " " << b << " " << c << " = " << atoi(a) * atoi(c) << endl;
		else if (strcmp(b, "/") == 0) cout << a << " " << b << " " << c << " = " << atoi(a) / atoi(c) << endl;
		else if (strcmp(b, "%") == 0) cout << a << " " << b << " " << c << " = " << atoi(a) % atoi(c) << endl;
	}
#endif
}