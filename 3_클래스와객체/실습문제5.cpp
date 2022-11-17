// ���� ���� �߻���Ű�� Random Ŭ������ ������.
// Random Ŭ������ �̿��Ͽ� ������ ������ 10�� ����ϴ� ��ʴ� ������ ����.
// Random Ŭ������ ������, next(), nextInRange()�� 3���� ��� �Լ��� �������� �ۼ��ϰ� main() �Լ��� ���� �ϳ��� cpp ���Ͽ� �����϶�.


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Random {
public:
	Random() { srand((unsigned)time(0)); } // ������ ������, �ٸ� �������� �߻���Ű�� ���� seed ����
	
	unsigned int next() { return rand(); } // 0���� RAND_MAX(32767) ������ ������ ���� �߻�

	unsigned int nextInRange(unsigned int x, unsigned int y) {
		unsigned int n;

		do {
			n = rand() % y;
		} while (n < x);
		return n;
	};
};

int main() {
	Random r;

	cout << "-- 0���� " << RAND_MAX << "������ ���� ���� 10 ��--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next(); // 0���� RAND_MAX(32767) ������ ������ ����
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2���� " << "4 ������ ���� ���� 10 �� --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4); // 2���� 4 ������ ������ ����
		cout << n << ' ';
	}
	cout << endl;
}