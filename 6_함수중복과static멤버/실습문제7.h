#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Random {
public:
	// 항상 다른 랜덤수를 발생시키기 위한 seed를 설정하는 함수
	static void seed() { srand((unsigned)time(0)); } // 씨드 설정
	static int nextInt(int min, int max); // min과 max 사이의 랜덤 정수 리턴
	static char nextAlphabet(); // 랜덤 알파벳 문자 리턴
	static double nextDouble(); // 0보다 크거나 같고 1보다 적은 랜덤 실수 리턴
};