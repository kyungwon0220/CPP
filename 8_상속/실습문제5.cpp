// ���� 5~6�� ����Ǵ� BaseArray Ŭ������ ������ ����.
// BaseArray�� ��ӹ޾� ťó�� �۵��ϴ� MyQueue Ŭ������ �ۼ��϶�.
// MyQueue�� Ȱ���ϴ� ��ʴ� ������ ����.

#include <iostream>

using namespace std;

class BaseArray {
private:
	int capacity; // �迭�� ũ��
	int* mem; // ���� �迭�� ����� ���� �޸��� ������
protected:
	BaseArray(int capacity = 100) { this->capacity = capacity; mem = new int[capacity]; }
	~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};

class MyQueue : private BaseArray {
private:
	int size; // ���� ť �ȿ� �ִ� �������� ����
	unsigned short front, rear;
public:
	MyQueue(int size) : BaseArray(size) { this->size = 0; this->front = -1; this->rear = -1; }
	void enqueue(int val) {
		if (this->size == this->getCapacity()-1) return; // ��ȭ �����̸�, ���� ���� �ߴ�

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
	cout << "ť�� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n); // ť�� ����
	}
	cout << "ť�� �뷮:" << mQ.capacity() << ", ť�� ũ��:" << mQ.length() << endl;
	cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' '; // ť���� �����Ͽ� ���
	}
	cout << endl << "ť�� ���� ũ�� : " << mQ.length() << endl;
}