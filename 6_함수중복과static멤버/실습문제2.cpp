// Person 클래스의 객체를 생성하는 ain() 함수는 다음과 같다.
// (1) 생성자를 중복 작성하고 프로그램을 완성하라.
// (2) 디폴트 매개 변수를 가진 하나의 생성자를 작성하고 프로그램을 완성하라.

#include <iostream>

using namespace std;

class Person {
	int id;
	double weight;
	string name;
public:
	void show() { cout << id << ' ' << weight << ' ' << name << endl; }
	Person(int id = 1, string name = "Grace", double weight = 20.5) {
		this->id = id;
		this->name = name;
		this->weight = weight;
	}
};

int main() {
	Person grace, ashley(2, "Ashley"), helen(3, "Helen", 32.5);
	grace.show();
	ashley.show();
	helen.show();
}