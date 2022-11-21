// 다음은 이름과 반지름을 속성으로 가진 Circle 클래스와 이들을 배열로 관리하는 CircleManager 클래스이다.
// 키보드에서 원의 개수를 입력받고, 그 개수만큼 원의 이름과 반지름을 입력받고, 다음과 같이 실행되도록 main() 함수를 작성하라.
// Circle, CircleManager 클래스도 완성하라.


#include <iostream>
#include <string>

using namespace std;

class Circle {
	int radius; // 원의 반지름 값
	string name; // 원의 이름
public:
	void setCircle(string name, int radius) { this->name = name; this->radius = radius; } // 이름과 반지름 설정
	double getArea() { return this->radius * this->radius * 3.14; }
	string getName() { return this->name; }
};


class CircleManager {
	Circle* p; // Circle 배열에 대한 포인터
	int size; // 배열의 크기
public:
	CircleManager(int size) { // size 크기의 배열을 동적 생성. 사용자로부터 입력 완료
		this->size = size;
		p = new Circle[size];

		string inputs;
		int findex;
		for (int i = 0; i < size; i++) {
			cout << "원 " << i + 1 << "의 이름과 반지름 >> ";
			getline(cin, inputs, '\n');
			findex = inputs.find(' ', 0); // 공백자 인덱스 값
			p[i].setCircle(inputs.substr(0, findex), stoi(inputs.substr(findex)));
		}
	}

	void searchByName(const string name) { // 사용자로부터 원의 이름을 입력받아 면적 출력
		for (unsigned short i = 0; i < this->size; i++)
			if (name.compare(p[i].getName()) == 0)
				cout << p[i].getName() << "의 면적은 " << p[i].getArea() << endl;
	}

	void searchByArea(const int area) { // 사용자로부터 면적을 입력받아 면적보다 큰 원의 이름 출력
		cout << area << "보다 큰 원을 검색합니다." << endl;

		for (unsigned short i = 0; i < this->size; i++) {
			if ((int)area < p[i].getArea())
				cout << p[i].getName() << "의 면적은 " << p[i].getArea() << ", ";
		}
	}


	~CircleManager() { delete[] p; }
};


int main() {
	int N;
	string inputs, name, searchArea;

	cout << "원의 개수 >> ";
	cin >> N;
	cin.ignore(); // 미입력시 ERR (버퍼 관련

	CircleManager manager(N);

	cout << "검색하고자 하는 원의 이름 >> ";
	cin >> name;
	manager.searchByName(name);

	cout << "최소 면적을 정수로 입력하세요 >> ";
	cin >> searchArea;
	manager.searchByArea(stoi(searchArea));
}