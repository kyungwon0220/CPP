#include "Test1Class.h"

Test::Test() {this->m_x = 1;} // 기본 생성자
Test::Test(const int x) :m_x(x) {}

void Test::setX(const int x) {
    this->m_x = x;
}
int Test::getX() {
    return this->m_x;
}