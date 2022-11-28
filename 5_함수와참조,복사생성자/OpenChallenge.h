#include <iostream>
#include <string>

using namespace std;

class Morse {
	string alphabet[26]; // ���ĺ��� �� ��ȣ ����
	string digit[10]; // ������ �� ��ȣ ����
	string slash, question, comma, period, plus, equal; // Ư�� ������ �� ��ȣ ����
public:
	Morse(); // alphabet[], digit[] �迭 �� Ư�� ������ �� ��ȣ �ʱ�ȭ
	void text2Morse(string text, string& morse); // ���� �ؽ�Ʈ�� �� ��ȣ�� ��ȯ
	bool morse2Text(string morse, string& text); // �� ��ȣ�� ���� �ؽ�Ʈ�� ��ȯ
};