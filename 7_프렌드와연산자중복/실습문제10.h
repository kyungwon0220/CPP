#include <iostream>

using namespace std;

class Statistics {
	int* n;
	unsigned short size = 0;
public:
	Statistics(); // 持失切
	~Statistics(); // 社瑚切

	bool operator!();
	Statistics& operator<<(int x);
	void operator~();
	void operator>>(int &avg);
};