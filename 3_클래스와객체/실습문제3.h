#include <string>
using namespace std;

class Account {
private:
	string name;
	unsigned long id;
	unsigned long balance; // �ܾ�
public:
	Account() :Account("kitae", 1, 5000) {}; // ���� ������
	Account(string name, int id, int balance);

	string getOwner();
	void deposit(int balance); // ����
	unsigned long withdraw(int money = 5000); // ��� // ��ݾ� ���� ������, 5000���� �ʱ�ȭ
	unsigned long inquiry(); // �ܾ�
};