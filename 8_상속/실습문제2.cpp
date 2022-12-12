// 문제 1~2에 적용되는 원을 추상화한 Circle 클래스가 있다.
// 다음과 같이 배열을 선언하여 다음 실행 결과가 나오도록 Circle을 상속받은 NamedCircle 클래스와 main() 함수 등 필요한 함수를 작성하라.

#include <iostream>
#include <string>

using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

class NamedCircle : public Circle {
	string name;
public:
	NamedCircle(int radius=0, string name="") : Circle(radius) { this->name = name; }
	string getName() { return this->name; }
	void setName(string name) { this->name = name; }
	void show() { cout << "반지름이 " << this->getRadius() << "인 " << this->getName() << endl; }
};

int main() {
	NamedCircle pizza[5];
	int max;
	unsigned short check;

	cout << "5 개의 정수 반지름과 원의 이름을 입력하세요" << endl;

	for(unsigned short i=0; i<5; i++) {
		cout << i + 1 << ">> ";
		
		int r;
		cin >> r;

		string name;
		getline(cin, name);

		pizza[i].setRadius(r);
		pizza[i].setName(name);
	}

	max = pizza[0].getRadius();
	
	for (unsigned short i = 1; i < 5; i++) {
		if (max < pizza[i].getRadius()) {
			check = i;
			max = pizza[i].getRadius();
		}
	}

	cout << "가장 면적이 큰 피자는 " << pizza[check].getName() << "입니다" << endl;
}