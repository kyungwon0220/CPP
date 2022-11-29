#include "실습문제4.h"

bool bigger(int a, int b, int& big) {
	if (a == b) {
		big = a;
		return true;
	}
	else {
		if (a > b) big = a;
		else big = b;
		
		return false;
	}
}