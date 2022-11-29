// find() �Լ��� ������ ������ ����.
// ���ڿ� a���� ���� c�� ã��, ���� c�� �ִ� ������ ���� ������ �����Ѵ�.
// ���� ���� c�� ã�� �� ���ٸ� success ���� �Ű� ������ false�� �����Ѵ�.
// ���� ã�� �Ǹ� success�� true�� �����Ѵ�.
// ���� main()�� �� ����ǵ��� find()�� �ۼ��϶�.


#include <iostream>

using namespace std;

char& find(char a[], char c, bool& success) {
	unsigned short len = strlen(a);

	for (unsigned short i = 0; i < len; i++) {
		if (a[i] == c) {
			success = true;
			return a[i];
		}
	}

	success = false;
}

int main() {
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);
	if (b == false) {
		cout << "M�� �߰��� �� ����" << endl;
		return 0;
	}
	loc = 'a'; // 'M' ��ġ�� 'm' ���
	cout << s << endl; // "mike"�� ��µ�
}