#include "�ǽ�����9.h"
Oval::Oval() :Oval(1, 1) {} // ���� ������
Oval::Oval(int width, int height) { this->width = width; this->height = height; } // Ÿ�� ������
Oval::~Oval() { std::cout << "Oval �Ҹ� : width = " << this->width << ", height = " << this->height << std::endl; } // �Ҹ��� ����

unsigned long Oval::getWidth() { return this->width; }
unsigned long Oval::getHeight() { return this->height; }
void Oval::set(int width, int height) { this->width = width; this->height = height; }
void Oval::show() { std::cout << "width = " << this->width << ", height = " << this->height << std::endl; };