// 다음과 같은 Sample 클래스가 있다.
// 다음 main() 함수가 실행되도록 Sample 클래스를 완성하라.


#include <iostream>
#include <string>

using namespace std;

class Sample {
	int* p;
	int size;
public:
	Sample(int n) { // 생성자
		size = n; p = new int[n]; // n개 정수 배열의 동적 생성
	}
	void read() { // 동적 할당받은 정수 배열 p에 사용자로부터 정수를 입력 받음
		for (int i = 0; i < this->size; i++) cin >> this->p[i];
	}
	void write() { // 정수 배열을 화면에 출력
		for (int i = 0; i < this->size; i++) cout << this->p[i] << ' ';
		cout << endl;
	}
	int big() { // 정수 배열에서 가장 큰 수 리턴
		int big = this->p[0];

		for (int i = 0; i < this->size; i++)
			if (big < this->p[i]) big = this->p[i];

		cout << "가장 큰 수는 ";
		return big;
	}
	~Sample() { // 소멸자
		delete[] p;
	}
};


int main() {
	Sample s(10); // 10개 정수 배열을 가진 Sample 객체 생성
	s.read(); // 키보드에서 정수 배열 읽기
	s.write(); // 정수 배열 출력
	cout << "가장 큰 수는 " << s.big() << endl; // 가장 큰 수 출력
}