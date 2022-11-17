// 문제 5번을 참고하여 생성자를 이용하여 짝수 홀수를 선택할 수 있도록 SelectableRandom 클래스를 작성하고 짝수 10개, 홀수 10개를 랜덤하게 발생시키는 프로그램을 작성하라.


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


class SelectableRandom {
public:
	SelectableRandom(unsigned short select) {
		srand((unsigned)time(0));

		if (select == 1) { // 홀수시를 ' 1 ' 입력으로 설계
			cout << "-- 0에서 " << RAND_MAX << "까지의 홀수 랜덤 정수 10 개--" << endl;

			for (int i = 0; i < 10; i++) {
				int n = odNext(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수
				cout << n << ' ';
			}
		} else if (select == 2) {// 짝수시를 2 입력으로 설계
			cout << "-- 0에서 " << RAND_MAX << "까지의 짝수 랜덤 정수 10 개--" << endl;
			for (int i = 0; i < 10; i++) {
				int n = evenNext(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수
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

	cout << "홀수(숫자 1), 짝수(숫자 2) 입력 >> ";
	cin >> select;

	SelectableRandom r(select);


	cout << endl << endl << "-- 2에서 " << "9 까지의 랜덤 홀수 정수 10 개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.odnextInRange(2, 9); // 2에서 9 사이의 랜덤한 정수
		cout << n << ' ';
	}
	cout << endl;
}