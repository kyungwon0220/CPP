#include <iostream>

using namespace std;

class ArrayUtility2 {
public:
	static int* concat(int s1[], int s2[], int size); // s1�� s2�� ������ ���ο� �迭�� ���� �����ϰ� ������ ����
	static int* remove(int s1[], int s2[], int size, int& retSize); // s1���� s2�� �ִ� ���ڸ� ��� ������ ���ο� �迭�� ���� �����Ͽ� ����. �����ϴ� �迭�� ũ��� retSize�� ����. retSize�� 0�� ��� NULL ����
};