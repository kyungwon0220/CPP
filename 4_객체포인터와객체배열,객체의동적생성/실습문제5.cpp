// string Ŭ������ �̿��Ͽ� ����ڰ� �Է��� ���� �� ���� �Է¹ް� ���� �ϳ��� �����ϰ� �����Ͽ� ����ϴ� ���α׷��� �ۼ��϶�.


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


int main() {
	string s;
	char text; // ���� ����
	int n, rindex;


	cout << "�Ʒ��� �� ���� �Է��ϼ���.(exit�� �Է��ϸ� �����մϴ�)" << endl;

	while(1) {
		cout << ">>";

		getline(cin, s, '\n');

		if (s.compare("exit") == 0) break; // ���� ����

		srand((unsigned)time(0)); // ������ ������, �ٸ� �������� �߻���Ű�� ���� seed ����
		n = rand(); // 0���� RAND_MAX(32767) ������ ������ ���� �߻�

		if (n % 2 == 0) {
			text = (int)(n % (int)26) + (int)65; // ���� �빮��
		}
		else {
			text = (int)(n % (int)26) + (int)97; // ���� �ҹ���
		}
		
		rindex = n % s.length(); // ���� �ε���

		while(s[rindex] == ' ') { rindex = n % s.length(); } // ���� �ε��� ��ġ�� ���ڰ� �����Ͻ�, �ٸ� ���� �ε�����

		s[rindex] = (char)text;

		cout << s << endl;
	}
}