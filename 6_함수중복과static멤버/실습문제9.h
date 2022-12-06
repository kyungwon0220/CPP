#include <iostream>

using namespace std;

class Board {
	static unsigned short i;
	static string *s;
public:
	static void add(string s);
	static void print();
};