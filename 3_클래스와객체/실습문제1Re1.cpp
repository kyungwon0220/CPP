#include "�ǽ�����1Re1.h"

Tower::Tower() : Tower(1) {} // ���� ������
Tower::Tower(unsigned long Height) { this->Height = Height; }

unsigned long Tower::getHeight() { return this->Height; }
