// ������ ������ ��ȯ�ϴ� �߻� Ŭ���� Converter�̴�.
// Converter Ŭ������ ��ӹ޾� km�� mile(����)�� ��ȯ�ϴ� KmToMile Ŭ������ �ۼ��϶�.
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

class KmToMile : public Converter {
	double convert(double src) { return src / this->ratio; }
	string getSourceString() { return "Km"; }
	string getDestString() { return "Mile"; }
public:
	KmToMile(double src) : Converter(src) {} // ������
};


int main() {
	KmToMile toMile(1.609344); // 1 mile�� 1.609344 Km
	toMile.run();
}