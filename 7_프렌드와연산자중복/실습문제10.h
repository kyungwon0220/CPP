#include <iostream>

using namespace std;

class Statistics {
	int* n;
	unsigned short size = 0;
public:
	Statistics(); // ������
	~Statistics(); // �Ҹ���

	bool operator!();
	Statistics& operator<<(int x);
	void operator~();
	void operator>>(int &avg);
};