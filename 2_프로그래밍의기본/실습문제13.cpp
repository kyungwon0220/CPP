// 중식당의 주문 과정을 C++ 프로그램으로 작성해보자. 다음 실행 결과와 같이 메뉴와 사람 수를 입력받고 이를 출력하면 된다. 잘못된 입력을 가려내는 부분도 코드에 추가하라.
// 목적 : C++ 프로그램 구성, 키 입력 등 종합 연습

#include <iostream>
#include <string>
using namespace std;

int main() {
	char chose;
	unsigned long n; // 인분
	string menu[3] = { "짬뽕", "짜장", "군만두" };

	cout << "***** 승리장에 오신 것을 환영합니다. *****" << endl;	
	
	do {
		cout << "짬뽕:1, 짜장:2, 군만두:3, 종료:4>>\t";
		
		cin >> chose;
		if (!(chose > '0' && chose <= '4')) { // 잘못된 입력시 재입력
			cout << "다시 주문하세요!!" << endl;
			cout << "입력 오류" << endl;
			continue;
		}
		
		if (chose == '4') {
			cout << "오늘 영업은 끝났습니다.";
			break;
		}
		else {
			cout << "몇인분?";
			cin >> n;

			if (cin.fail()) { // 정수대신 문자열이 입력되어 오류가 발생하는 경우 대처. 부록 C의 예제 C-1참고
				cin.clear();
				cin.ignore(100, '\n'); // 100글자까지 읽어들임 or '\n' 입력되면 종료
				cout << "입력 오류" << endl;
				continue;
			}

			cout << menu[chose - '1'] << " " << n << "인분 나왔습니다" << endl;
		}		
	} while (chose != '4');
}