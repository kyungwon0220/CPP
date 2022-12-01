// Up & Down ���� ���α׷��� �ۼ��غ���.
// ���ӿ� �����ϴ� ����� 2���̸�, ������ ���� ������ ���� ������ �信 ������ ����.
// Up & Down ������ ��ü������ UpAndDownGame Ŭ������ �ۼ��ϰ� static ����θ� �����϶�.
// ������ ǥ���ϱ� ���� Person Ŭ������ �ۼ��ϰ� main() �Լ��� ���α׷��� ���۽�Ű�� ��� �����θ� �����϶�.


#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


class Person {
private:
	string name;	
public:
	Person(string name) { this->name = name; }
	string getName() { return this->name; }
	void setName(string name) { this->name = name; }
};

class UpAndDownGame {
private:
	static int random;
	static unsigned short loww;
	static unsigned short highh;
public:
	static void gameRun(){
		srand((unsigned)time(0)); // �׻� �ٸ� �������� �߻���Ű�� ���� seed ����
		UpAndDownGame::random = rand()%100; // 0���� RAND_MAX(32767) ������ ������ ���� % 100 == n

		Person* p = new Person[2]{ Person("���μ�"), Person("������") };

		cout << "Up & Down ������ �����մϴ�." << endl;

		unsigned short i = 0;
		unsigned short check;

		do {
			cout << "���� " << loww << "�� " << highh << "���̿� �ֽ��ϴ�." << endl;
			cout << p[i % 2].getName() << ">>";
			cin >> check;

			cout << "nowRand:" << UpAndDownGame::random << endl;
			if (UpAndDownGame::random > check) UpAndDownGame::loww = check;
			else if (UpAndDownGame::random < check) UpAndDownGame::highh = check;
			else if (UpAndDownGame::random == check) cout << p[i % 2].getName() << "�� �̰���ϴ�!!" << endl;

			i++;
		} while (check != UpAndDownGame::random);
		
	}
};

unsigned short UpAndDownGame::loww = 0;
unsigned short UpAndDownGame::highh = 99;
int UpAndDownGame::random;

int main() {	
	UpAndDownGame::gameRun();
}