#include <iostream>

class Oval {
private:
	unsigned long width;
	unsigned long height;
public:
	Oval(); // �⺻ ������
	Oval(int width, int height); // �Ű� ���� �ִ� ������
	~Oval(); // �Ҹ��� ����

	unsigned long getWidth();
	unsigned long getHeight();
	void set(int width, int height);
	void show();
};