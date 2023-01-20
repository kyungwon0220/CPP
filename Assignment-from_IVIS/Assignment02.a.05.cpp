#include<iostream>

int main() {
    unsigned short n;
    
    std::cout << "Input number of rows: ";
    std::cin >> n;

    if (n > 9) {
        std::cout << "ERR: 입력값 MAX = 9(초과하여 종료." << std::endl;
        exit(1);
    }
    
    for (unsigned short i = 0; i < n; i++) {
        for (unsigned short k = n-i; k > 0; k--) {
            std::cout << " ";
        }
        for (unsigned short j = 1; j <= i+1; j++) {
            std::cout << j;
        }
        for (unsigned short j = i; j >= 1; j--) {
            std::cout << j;
        }
        std::cout << std::endl;
    }
    return 0;
}