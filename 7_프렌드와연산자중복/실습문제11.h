#include <iostream>

using namespace std;

class Stack {
	int* x;
	unsigned short index = 0;
public:
	Stack(); // 持失切
	~Stack(); // 社瑚切

	Stack& operator<<(int x);
	Stack& operator>>(int &x);
	bool operator!();
};