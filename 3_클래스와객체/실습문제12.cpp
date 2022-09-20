#include "실습문제12.h"

Ram::Ram() { // 생성자
	for(int i=0; i<sizeof(mem) / sizeof(mem[0]); i++) this->mem[i] = ((int)0);

	this->size = 100 * 1024;
}

Ram::~Ram() { std::cout << "메모리 제거됨" << std::endl; } // 소멸자

char Ram::read(int address) { return mem[address]; }

void Ram::write(int address, char value) { this->mem[address] = value; }