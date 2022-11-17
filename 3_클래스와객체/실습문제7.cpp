// ���� 5���� �����Ͽ� �����ڸ� �̿��Ͽ� ¦�� Ȧ���� ������ �� �ֵ��� SelectableRandom Ŭ������ �ۼ��ϰ� ¦�� 10��, Ȧ�� 10���� �����ϰ� �߻���Ű�� ���α׷��� �ۼ��϶�.


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


class SelectableRandom {
public:
	SelectableRandom(unsigned short select) {
		srand((unsigned)time(0));

		if (select == 1) { // Ȧ���ø� ' 1 ' �Է����� ����
			cout << "-- 0���� " << RAND_MAX << "������ Ȧ�� ���� ���� 10 ��--" << endl;

			for (int i = 0; i < 10; i++) {
				int n = odNext(); // 0���� RAND_MAX(32767) ������ ������ ����
				cout << n << ' ';
			}
		} else if (select == 2) {// ¦���ø� 2 �Է����� ����
			cout << "-- 0���� " << RAND_MAX << "������ ¦�� ���� ���� 10 ��--" << endl;
			for (int i = 0; i < 10; i++) {
				int n = evenNext(); // 0���� RAND_MAX(32767) ������ ������ ����
				cout << n << ' ';
			}
		}
	}

	unsigned int evenNext() {
		unsigned n = rand();

		while (n % 2 != 0) n = rand();
		
		return n;
	}

	unsigned int odNext() {
		unsigned n = rand();

		while (n % 2 == 0) n = rand();

		return n;
	}

	unsigned int odnextInRange(unsigned x, unsigned y) {
		unsigned int n;

		do {
			n = rand() % y;
		} while (n < x || n % 2 == 0);

		return n;
	}
};

int main() {
	unsigned short select;

	cout << "Ȧ��(���� 1), ¦��(���� 2) �Է� >> ";
	cin >> select;

	SelectableRandom r(select);


	cout << endl << endl << "-- 2���� " << "9 ������ ���� Ȧ�� ���� 10 �� --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.odnextInRange(2, 9); // 2���� 9 ������ ������ ����
		cout << n << ' ';
	}
	cout << endl;
}