// ���� 5���� �����Ͽ� ¦�� ������ �����ϰ� �߻���Ű�� EvenRandom Ŭ������ �ۼ��ϰ� EvenRandom Ŭ������ �̿��Ͽ� 10���� ¦���� �����ϰ� ����ϴ� ���α׷��� �ϼ��϶�.
// 0�� ¦���� ó���Ѵ�.


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


class EvenRandom {
public:
	EvenRandom() { srand((unsigned)time(0)); }

	unsigned int evenNext() {
		unsigned n = rand();

		while (n % 2 != 0) n = rand();
		
		return n;
	}

	unsigned int EvennextInRange(unsigned x, unsigned y) {
		unsigned int n;

		do {
			n = rand() % y;
		} while (n < x || n % 2 != 0);

		return n;
	}
};

int main() {
	EvenRandom r;

	cout << "-- 0���� " << RAND_MAX << "������ ���� ���� 10 ��--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.evenNext(); // 0���� RAND_MAX(32767) ������ ������ ����
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2���� " << "4 ������ ���� ���� 10 �� --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.EvennextInRange(2, 10); // 2���� 10 ������ ������ ����
		cout << n << ' ';
	}
	cout << endl;
}