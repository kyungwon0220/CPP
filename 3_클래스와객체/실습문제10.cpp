#include "실습문제10.h"

void Add::setValue(int a, int b) { this->a = a; this->b = b; }
int Add::calculate() { return a + b; }

void Sub::setValue(int a, int b) { this->a = a; this->b = b; }
int Sub::calculate() { return a - b; }

void Mul::setValue(int a, int b) { this->a = a; this->b = b; }
int Mul::calculate() { return a * b; }

void Div::setValue(int a, int b) { this->a = a; this->b = b; }
int Div::calculate() { return a / b; }