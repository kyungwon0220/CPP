// �Ʒ��� ���� BaseMemory Ŭ������ ��ӹ޴� ROM(Read Only Memory), RAM Ŭ������ �ۼ��϶�.
// BaseMemory�� �ʿ��� �ڵ带 ���� �߰��Ͽ� ������ �ϼ��϶�.
// ROM�� �б� ���� �޸��̹Ƿ� �۵� �߿� ���� �� ���� ���� ������, ���忡�� ������ �� �����ڰ� ��û�� �����ͷ� �ʱ�ȭ �ϴµ� �� �۾��� ���´�(burn)��� �Ѵ�.
// �׷��Ƿ� ROM�� �ݵ�� �����ڿ��� burn �۾��� �Ͼ�� �Ѵ�.
//������ ROM�� RAM �޸𸮸� �����ϰ� ����ϴ� ����̴�.
// ROM�� 0�������� 4�������� �о� RAM �޸��� 0~4������ ����, �ٽ� RAM �޸��� ���� ȭ�鿡 ����Ѵ�.
// ��ü ���α׷��� �ϼ��϶�.

#include <iostream>

using namespace std;

class BaseMemory {
	char* mem;
protected:
	BaseMemory(int size) { mem = new char[size]; }
	void burn(unsigned short index, char val) { this->mem[index] = val; }
	char getMem(int i) { return this->mem[i]; }
};

class ROM : private BaseMemory {
public:
	ROM(int size, char* rp, unsigned short len) : BaseMemory(size) {
		for (unsigned short i = 0; i < len; i++) this->burn(i, rp[i]);
	}
	char read(int i) { return this->getMem(i); }
};

class RAM : private BaseMemory {
public:
	RAM(int size) : BaseMemory(size) {}
	void write(int i, char c) { this->burn(i, c); }
	char read(int i) { return this->getMem(i); }
};

int main() {
	char x[5] = { 'h', 'e', 'l', 'l', 'o' };
	
	ROM biosROM(1024 * 10, x, 5); // 10KB�� ROM �޸�. �迭 x�� �ʱ�ȭ��
	RAM mainMemory(1024 * 1024); // 1MB�� RAM �޸�

	// 0 �������� 4�������� biosROM���� �о� mainMemory�� ����
	for (int i = 0; i < 5; i++) mainMemory.write(i, biosROM.read(i));
	for (int i = 0; i < 5; i++) cout << mainMemory.read(i);
}