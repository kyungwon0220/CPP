// string Ŭ������ �̿��Ͽ� ����ڰ� �Է��� ���� �� ���� ���ڿ��� �Է¹ް� �Ųٷ� ����ϴ� ���α׷��� �ۼ��϶�.


#include <iostream>
#include <string>

using namespace std;


int main() {
	string s;


	cout << "�Ʒ��� �� ���� �Է��ϼ���.(exit�� �Է��ϸ� �����մϴ�)" << endl;

	while (1) {
		cout << ">>";
		getline(cin, s, '\n');

		if (s.compare("exit") == 0) break; // ���� ����

		for (short i = s.length() - 1; i >= 0; i--) cout << s.at(i);
		
		cout << endl;
	}
	
}