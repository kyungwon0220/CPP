#include "�ǽ�����4.h"
#include <iostream>

CoffeeMachine::CoffeeMachine(int coffee = 5, int water = 10, int suger = 3) {
	this->coffee = coffee;
	this->water = water;
	this->suger = suger;
}
void CoffeeMachine::drinkEspresso() {
	this->coffee -= 1;
	this->water -= 1;
}

void CoffeeMachine::drinkAmericano() {
	this->coffee -= 1;
	this->water -= 2;
}

void CoffeeMachine::drinkSugarCoffee() {
	this->coffee -= 1;
	this->water -= 2;
	this->suger -= 1;
}

void CoffeeMachine::fill() {
	this->coffee = 10;
	this->water = 10;
	this->suger = 10;
}

void CoffeeMachine::show() {
	std::cout << "Ŀ�� �ӽ� ����, Ŀ��:" << this->coffee << "\t��:" << this->water << "\t����:" << this->suger << std::endl;
}