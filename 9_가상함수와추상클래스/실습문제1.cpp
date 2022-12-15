// ������ ������ ��ȯ�ϴ� �߻� Ŭ���� Converter�̴�.
// Converter Ŭ������ ��ӹ޾� �޷��� ��ȭ�� ȯ���ϴ� WonToDollar Ŭ������ �ۼ� �϶�.
// main() �Լ��� ���� ����� ������ ����.

#include <iostream>

using namespace std;

class Converter {
protected:
	double ratio;
	virtual double convert(double src) = 0; // src�� �ٸ� ������ ��ȯ�Ѵ�.
	virtual string getSourceString() = 0; // src ���� ��Ī
	virtual string getDestString() = 0; // dest ���� ��Ī
public:
	Converter(double ratio) { this->ratio = ratio; } // ������

	void run() {
		double src;
		cout << getSourceString() << "�� " << getDestString() << "�� �ٲߴϴ�. ";
		cout << getSourceString() << "�� �Է��ϼ���>> ";
		cin >> src;
		cout << "��ȯ ��� : " << convert(src) << getDestString() << endl;
	}
};

class WonToDollar : public Converter {
	string src;
	string dest;
	double convert(double src) { return (src / ratio); }
	string getSourceString() { return this->src; }
	string getDestString() { return this->dest; }
public:
	WonToDollar(double ratio) : Converter(ratio) { this->src = "��"; this->dest = "�޷�"; } // ������
};


int main() {
	WonToDollar wd(1010); // 1 �޷��� 1010��
	wd.run();
}