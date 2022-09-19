// CoffeeMachine 클래스를 만들어보자. main() 함수와 실행 결과가 다음과 같도록
// CoffeeMachine 클래스를 작성하라. 에스프레소 한 잔에는 커피와 물이 각각 1식 소
// 비되고, 아메리카노의 경우 커피는 1, 물은 2가 소비되고, 설탕 커피는 커피1, 물2,
// 설탕 1이 소비된다. CoffeeMachine 클래스에는 어떤 멤버 변수와 어떤 멤버 함수가
// 필요한지 잘 판단하여 작성하라.
/*
* 커피 머신 상태, 커피:4 물:9 설탕:3 // java.show();의 실행 결과
* 커피 머신 상태, 커피:3 물:7 설탕:3
* 커피 머신 상태, 커피:2 물:5 설탕:2
* 커피 머신 상태, 커피:10 물:10 설탕:10
*/

#include "실습문제4.h"

int main() {
	CoffeeMachine java(5, 10, 3);
	java.drinkEspresso();
	java.show();
	java.drinkAmericano();
	java.show();
	java.drinkSugarCoffee();
	java.show();
	java.fill();
	java.show();
}