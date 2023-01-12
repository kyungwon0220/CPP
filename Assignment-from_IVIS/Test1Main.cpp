#include "Test1Class.h"


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

    t1 = nullptr;
    t2 = nullptr;
    delete t1;
    delete t2;
    return 0;
}
