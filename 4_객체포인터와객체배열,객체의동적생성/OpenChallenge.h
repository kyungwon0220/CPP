#include <iostream>
#include <string>

using namespace std;


class WordGame {
public:
	WordGame(unsigned short playerNum);
};

class Player {
private:
	string name;
public:
	string getname();
	void setname(string name);
};