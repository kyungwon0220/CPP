// �����ڷ� ������ �ؽ�Ʈ�� ���� �� ���ĺ��� �ش��ϴ� ���ڰ� �� ������ ����ϴ� ������׷� Ŭ���� Histogram�� ������.
// �빮�ڴ� ��� �ҹ��ڷ� ��ȯ�Ͽ� ó���Ѵ�.
// Histogram Ŭ������ Ȱ���ϴ� ��ʿ� ���� ����� ������ ����.


#include "�ǽ�����13.h"

int main() {
	string inputS;

	getline(cin, inputS, '\n');

	Histogram elvisHisto(inputS);

	elvisHisto.print();
}