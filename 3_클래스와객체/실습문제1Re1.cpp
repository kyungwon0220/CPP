#include "실습문제1Re1.h"

Tower::Tower() : Tower(1) {} // 위임 생성자
Tower::Tower(unsigned long Height) { this->Height = Height; }

unsigned long Tower::getHeight() { return this->Height; }
