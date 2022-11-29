#include "실습문제1.h"

Circle::Circle() : Circle(1) {} // 위임 생성자
Circle::Circle(double rad) { this->radius = rad; }
Circle::Circle(const Circle& c) { this->radius = c.radius; } // 얕은 디폴드 복사 생성자
double Circle::getRadius() { return this->radius; }


void swap(Circle& c1, Circle& c2) {
	Circle tmp(c1); // 복사 생성
	c1 = c2;
	c2 = tmp;
}