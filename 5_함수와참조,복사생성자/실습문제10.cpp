// ������ �����ϴ� �ڵ带 �ۼ��غ���.
// ���� �ڵ�� ���� ����� �����Ͽ� append() �Լ��� �ۼ��ϰ� ��ü ���α׷��� �ϼ��϶�.
// append()�� Buffer ��ü�� ���ڿ��� �߰��ϰ� Buffer ��ü�� ���� ������ ��ȯ�ϴ� �Լ��̴�.


#include <iostream>

using namespace std;

class Buffer {
	string text;
public:
	Buffer(string text) { this->text = text; }
	void add(string next) { text += next; } // text�� next ���ڿ� �����̱�
	void print() { cout << text << endl; }
};

Buffer& append(Buffer& b, string s) { b.add(s); return b; }

int main() {
	Buffer buf("Hello");
	Buffer& temp = append(buf, "Guys"); // buf�� ���ڿ��� "Guys" ������
	temp.print(); // "HelloGuys" ���
	buf.print(); // "HelloGuys" ���
}