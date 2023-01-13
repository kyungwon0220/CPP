#include "Test1Class.h"
#include <iostream>

int main() {
    int x = 55;
    int x2;
    Test *t1 = new Test(x);
    Test *t2 = new Test;

    std::cout << t1->getX() << std::endl;

    std::cout << "Input New X: ";
    std::cin >> x2;
    t2->setX(x2);
    std::cout << t2->getX() << std::endl;

    delete t1;
    delete t2;
    t1 = nullptr;
    t2 = nullptr;
    
    return 0;
}
