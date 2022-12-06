#include <iostream>

using namespace std;

class Trace {
	static string tag[100];
	static string info[100];
	static unsigned short i;
public:	
	static void put(string tag, string info);
	static void print(string tag = "¸ðµç Trace");
};