#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Random {
public:
	// �׻� �ٸ� �������� �߻���Ű�� ���� seed�� �����ϴ� �Լ�
	static void seed() { srand((unsigned)time(0)); } // ���� ����
	static int nextInt(int min, int max); // min�� max ������ ���� ���� ����
	static char nextAlphabet(); // ���� ���ĺ� ���� ����
	static double nextDouble(); // 0���� ũ�ų� ���� 1���� ���� ���� �Ǽ� ����
};