#include "�ǽ�����3.h"

Account::Account(string name, int id, int balance) {
	this->name = name;
	this->id = id;
	this->balance = balance;
}
string Account::getOwner() { return this->name; }

void Account::deposit(int balance) { this->balance += balance; }

unsigned long Account::inquiry() { return this->balance; }

unsigned long Account::withdraw(int money) {
	if (money > this->balance) { // ����� ���� ã�� �ݾ׺��� ���� ���
		money = this->balance;
		this->balance = 0;
	}
	else this->balance -= money;
	return money; // ���� ã�� �ݾ� ����
}