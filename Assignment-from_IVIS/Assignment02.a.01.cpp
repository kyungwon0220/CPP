// Create application that calculates factorial of a number using recursion and without it (make 2 separate functions).
// 재귀를 사용하거나 사용하지 않고 숫자의 계승을 계산하는 응용 프로그램을 만듭니다(별도의 함수 2개 만들기).


#include "Assignment02.a.01.h"

int main() {
    int x;

    std::cout << "Input number: ";
    std::cin >> x;

    std::cout << "Factorial of " << x << " is " << Factorial(x) << std::endl;

    return 0;
}
