// ���� main() �Լ��� ���� ����� �����Ͽ� half() �Լ��� �ۼ��϶�.


#include <iostream>

using namespace std;

void half(double& n) {
	n /= 2;
}

int main() {
	double n = 20;
	half(n); // n�� �ݰ��� ���� n�� �ٲ۴�.
	cout << n;
}
