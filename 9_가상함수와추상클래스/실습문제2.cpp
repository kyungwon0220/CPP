// 다음은 단위를 변환하는 추상 클래스 Converter이다.
// Converter 클래스를 상속받아 km를 mile(마일)로 변환하는 KmToMile 클래스를 작성하라.
// main() 함수와 실행 결과는 다음과 같다.

#include <iostream>

using namespace std;

class Converter {
protected:
	double ratio;
	virtual double convert(double src) = 0; // src를 다른 단위로 변환한다.
	virtual string getSourceString() = 0; // src 단위 명칭
	virtual string getDestString() = 0; // dest 단위 명칭
public:
	Converter(double ratio) { this->ratio = ratio; } // 생성자

	void run() {
		double src;
		cout << getSourceString() << "을 " << getDestString() << "로 바꿉니다. ";
		cout << getSourceString() << "을 입력하세요>> ";
		cin >> src;
		cout << "변환 결과 : " << convert(src) << getDestString() << endl;
	}
};

class KmToMile : public Converter {
	double convert(double src) { return src / this->ratio; }
	string getSourceString() { return "Km"; }
	string getDestString() { return "Mile"; }
public:
	KmToMile(double src) : Converter(src) {} // 생성자
};


int main() {
	KmToMile toMile(1.609344); // 1 mile은 1.609344 Km
	toMile.run();
}