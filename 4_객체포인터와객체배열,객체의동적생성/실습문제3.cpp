// string Ŭ������ �̿��Ͽ� ��ĭ�� �����ϴ� ���ڿ��� �Է¹ް� ���ڿ����� 'a'�� � �ִ��� ����ϴ� ���α׷��� �ۼ��غ���.

#include <iostream>
#include <string>

using namespace std;

int main() {
	string a;
	unsigned int count = 0;
	
	cout << "���ڿ� �Է�>>";
	getline(cin, a, '\n');

	//for (unsigned short i = 0; i < a.length(); i++) if (a.at(i) == 'a') count++;

	short index = 0;
	while (a.find('a', index) != -1) {
		count++;
		index = a.find('a', index) + 1;
	}
	
	cout << "���� a�� " << count << "�� �ֽ��ϴ�.";
}