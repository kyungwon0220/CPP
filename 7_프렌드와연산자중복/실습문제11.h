#include <iostream>

using namespace std;

class Stack {
	int* x;
	unsigned short index = 0;
public:
	Stack(); // ������
	~Stack(); // �Ҹ���

	Stack& operator<<(int x);
	Stack& operator>>(int &x);
	bool operator!();
};