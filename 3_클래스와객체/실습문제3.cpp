#include "실습문제3.h"

Account::Account(string name, int id, int balance) {
	this->name = name;
	this->id = id;
	this->balance = balance;
}
string Account::getOwner() { return this->name; }

void Account::deposit(int balance) { this->balance += balance; }

unsigned long Account::inquiry() { return this->balance; }

unsigned long Account::withdraw(int money) {
	if (money > this->balance) { // 저축된 돈이 찾는 금액보자 작은 경우
		money = this->balance;
		this->balance = 0;
	}
	else this->balance -= money;
	return money; // 실제 찾은 금액 리턴
}