// Person Ŭ������ ��ü�� �����ϴ� ain() �Լ��� ������ ����.
// (1) �����ڸ� �ߺ� �ۼ��ϰ� ���α׷��� �ϼ��϶�.
// (2) ����Ʈ �Ű� ������ ���� �ϳ��� �����ڸ� �ۼ��ϰ� ���α׷��� �ϼ��϶�.

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