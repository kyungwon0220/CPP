#include <string>
using namespace std;

class Account {
private:
	string name;
	unsigned long id;
	unsigned long balance; // 잔액
public:
	Account() :Account("kitae", 1, 5000) {}; // 위임 생성자
	Account(string name, int id, int balance);

	string getOwner();
	void deposit(int balance); // 저금
	unsigned long withdraw(int money = 5000); // 출금 // 출금액 인자 없을시, 5000으로 초기화
	unsigned long inquiry(); // 잔액
};