#include "실습문제9.h"
Oval::Oval() :Oval(1, 1) {} // 위임 생성자
Oval::Oval(int width, int height) { this->width = width; this->height = height; } // 타겟 생성자
Oval::~Oval() { std::cout << "Oval 소멸 : width = " << this->width << ", height = " << this->height << std::endl; } // 소멸자 구현

unsigned long Oval::getWidth() { return this->width; }
unsigned long Oval::getHeight() { return this->height; }
void Oval::set(int width, int height) { this->width = width; this->height = height; }
void Oval::show() { std::cout << "width = " << this->width << ", height = " << this->height << std::endl; };