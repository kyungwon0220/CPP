// 커피를 주문하는 간단한 C++ 프로그램을 작성해보자.
// 커피 종류는 "에스프레소", "아메리카노", "카푸치노"의 3가지이며 가격은 각각 2000원, 2300원, 2500원이다.
// 하루에 20000원 이상 벌게 되면 카페를 닫는다.
// //실행 결과와 같이 작동하는 프로그램을 작성하라.
// 목적 : C++ 프로그램 구성, cin, trcmp() 활용 종합 연습

#include <iostream>

using namespace std;

int main() {
	char coffee[100]; // 커피 이름
	int num; // 잔 수
	unsigned long price;
	int sum = 0; // 총 판매 금액

	cout << "에스프레소 2000원, 아메리카노 2300원, 카푸치노 2500원입니다." << endl << "주문 >>\t";

	do {
		cin >> coffee >> num;

		if (strcmp(coffee, "에스프레소") == 0) {
			price = num * 2000;
			cout << price << "원입니다. 맛있게 드세요" << endl;

			sum += price;
		}
		else if (strcmp(coffee, "아메리카노") == 0) {
			price = num * 2300;
			cout << price << "원입니다. 맛있게 드세요" << endl;

			sum += price;
		}
		else if (strcmp(coffee, "카푸치노") == 0) {
			price = num * 2500;
			cout << price << "원입니다. 맛있게 드세요" << endl;

			sum += price;
		}
	} while (sum < 20000);

	cout << "오늘 22200원을 판매하여 카페를 닫습니다. 내일 봐요~~~";
}