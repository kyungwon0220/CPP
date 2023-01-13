#ifndef __TESTH__
#define __TESTH__

class Test {
public:
    Test();
    Test(const int x);
    virtual ~Test() {} // virtual ~Test() = default;
    void setX(const int x);
    int getX();
private:
    int m_x;
};
#endif