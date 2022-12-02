// 다음 클래스에 중복된 생성자를 디폴트 매개 변수를 가진 하나의 생성자로 작성하고 테스트 프로그램을 작성하라.

#include <iostream>

using namespace std;

class MyVector {
	int* mem;
	int size;
public:
	MyVector() { mem = new int[100]; size = 100; for (int i = 0; i < size; i++) mem[i] = 0; }
	MyVector(int n, int val) { mem = new int[n]; size = n; for (int i = 0; i < size; i++) mem[i] = val; }
	~MyVector() { delete[] mem; }
	void testPrint() { for (int i = 0; i < size; i++) cout << i << " : " << mem[i] << endl; }
};
int main() {
	MyVector test1;
	MyVector test2(5, 25);

	test2.testPrint();
}