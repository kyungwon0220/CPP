// Create application that calculates factorial of a number using recursion and without it (make 2 separate functions).
// 재귀를 사용하거나 사용하지 않고 숫자의 계승을 계산하는 응용 프로그램을 만듭니다(별도의 함수 2개 만들기).


#include "Assignment02.a.01.h"

int main() {
    unsigned long x;

    std::cout << "Input number: ";
    std::cin >> x;

    if (x > 20) {
        std::cout << "ERR:too Big" << std::endl;
    } else if (x == 0) {
        std::cout << "ERR:x=0" << std::endl;
    } else {
        std::cout << "Factorial of " << x << " is " << Factorial(x) << std::endl;
    }
    
    std::cout << std::endl << "* Factorial() Recursion *" << std::endl;
    std::cout << "Input number: ";
    std::cin >> x;

    if (x > 20) {
        std::cout << "ERR:too Big" << std::endl;
    } else if (x == 0) {
        std::cout << "ERR:x=0" << std::endl;
    } else {
        std::cout << "Factorial of " << x << " is " << Factorial_Recursion(x) << std::endl;
    }
    
    return 0;
}
