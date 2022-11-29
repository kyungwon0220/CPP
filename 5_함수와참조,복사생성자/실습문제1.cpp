#include "�ǽ�����1.h"

Circle::Circle() : Circle(1) {} // ���� ������
Circle::Circle(double rad) { this->radius = rad; }
Circle::Circle(const Circle& c) { this->radius = c.radius; } // ���� ������ ���� ������
double Circle::getRadius() { return this->radius; }


void swap(Circle& c1, Circle& c2) {
	Circle tmp(c1); // ���� ����
	c1 = c2;
	c2 = tmp;
}