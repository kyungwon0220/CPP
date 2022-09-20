#include <iostream>

class Oval {
private:
	unsigned long width;
	unsigned long height;
public:
	Oval(); // 기본 생성자
	Oval(int width, int height); // 매개 변수 있는 생성자
	~Oval(); // 소멸자 선언

	unsigned long getWidth();
	unsigned long getHeight();
	void set(int width, int height);
	void show();
};