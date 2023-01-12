#ifndef __TESTH__
#define __TESTH__

#include <iostream>

class Test {
public:
    Test();
    Test(const int& x);
    void setX(const int& x);
    int getX();
private:
    int m_x;
};
#endif

