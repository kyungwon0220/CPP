// 한 라인에 ';'으로 5개의 이름을 구분하여 입력받아, 각 이름을 끊어내어 화면에 출력하고 가장 긴 이름을 판별하라.
// 목적 : cin.getline()으로 문자열 읽기

#include <iostream>
#include <string>

using namespace std;

int main() {
	char name[5][100];
	unsigned long count;
	char max[100];

	cout << "5 명의 이름을 ';'으로 구분하여 입력하세요";
	
	for (int i = 0; i < 5; i++) cin.getline(name[i], 100, ';');

	strcpy_s(max, name[0]);
	count = strlen(max);
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << " : " << name[i] << endl;
		if (count < strlen(name[i])) {
			count = strlen(name[i]);
			strcpy_s(max, name[i]);
		}
	}

	cout << "가장 긴 이름은 " << max;
}