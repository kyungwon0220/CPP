#include "�ǽ�����12.h"

Ram::Ram() { // ������
	for(int i=0; i<sizeof(mem) / sizeof(mem[0]); i++) this->mem[i] = ((int)0);

	this->size = 100 * 1024;
}

Ram::~Ram() { std::cout << "�޸� ���ŵ�" << std::endl; } // �Ҹ���

char Ram::read(int address) { return mem[address]; }

void Ram::write(int address, char value) { this->mem[address] = value; }