// ������׷��� ǥ���ϴ� Histogram Ŭ������ ����� <<, ! �����ڸ� �ۼ��غ���.
// Histogram Ŭ������ ������ ���ĺ��� �ٷ�� �빮�ڴ� ��� �ҹ��ڷ� ��ȯ�Ͽ� ó���Ѵ�.
// Histogram Ŭ������ Ȱ���ϴ� �ڵ� ��ʴ� ������ ����.
#include "OpenChallenge.h"

int main() {// falling in love with you. - by kit
	Histogram song("Wise men say, \nonly fools rush in But I can't help, \n");
	song << "falling" << " in love with you." << "- by "; // ������׷��� ���ڿ� �߰�
	song << 'k' << 'i' << 't'; // ������׷��� ���� �߰�
	!song; // ������׷� �׸���
}