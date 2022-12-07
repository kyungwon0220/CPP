#include "실습문제5.h"

Color Color::operator+(Color c) {
	Color tmp;
	tmp.red = this->red + c.red;
	tmp.green = this->green + c.green;
	tmp.blue = this->blue + c.blue;
	return tmp;
}

bool Color::operator==(Color& c) { if (this->red == c.red && this->green == c.green && this->blue == c.blue) return true; else return false; }

