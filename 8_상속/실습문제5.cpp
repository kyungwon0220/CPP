// 문제 5~6에 적용되는 BaseArray 클래스는 다음과 같다.
// BaseArray를 상속받아 큐처럼 작동하는 MyQueue 클래스를 작성하라.
// MyQueue를 활용하는 사례는 다음과 같다.

#include <iostream>

using namespace std;

class BaseArray {
private:
	int capacity; // 배열의 크기
	int* mem; // 정수 배열을 만들기 위한 메모리의 포인터
protected:
	BaseArray(int capacity = 100) { this->capacity = capacity; mem = new int[capacity]; }
	~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};

class MyQueue : private BaseArray {
private:
	int size; // 현재 큐 안에 있는 데이터의 개수
	unsigned short front, rear;
public:
	MyQueue(int size) : BaseArray(size) { this->size = 0; this->front = -1; this->rear = -1; }
	void enqueue(int val) {
		if (this->size == this->getCapacity()-1) return; // 포화 상태이면, 삽입 연산 중단

		this->put(++rear, val);
		//rear = rear % capacity();
		this->size++;
	}
	int capacity() { return this->getCapacity(); }
	int length() { return this->size; }
	int dequeue() {
		if (this->size == 0) return -1; // queue empty error

		this->size--;
		//front = front % capacity();
		return this->get(++front);
	}
};

int main() {
	MyQueue mQ(100);
	int n;
	cout << "큐에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n); // 큐에 삽입
	}
	cout << "큐의 용량:" << mQ.capacity() << ", 큐의 크기:" << mQ.length() << endl;
	cout << "큐의 원소를 순서대로 제거하여 출력한다>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' '; // 큐에서 제거하여 출력
	}
	cout << endl << "큐의 현재 크기 : " << mQ.length() << endl;
}