#include "OpenChallenge.h"

Exp::Exp() : Exp(1) {}
Exp::Exp(int base) { this->base = base; this->exp = 1; }
Exp::Exp(int base, int exp) { this->base = base; this->exp = exp; }

int Exp::getValue() {
	int result = 1;

	for (int i = 1; i < exp; i++) result *= this->base;

	return result * this->base;
}
int Exp::getBase() { return this->base; }
int Exp::getExp() { return this->exp; }
bool Exp::equals(Exp b) { return ( this->getValue() == b.getValue() ); }