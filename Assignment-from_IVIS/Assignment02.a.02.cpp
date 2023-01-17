#include <iostream>
#include <string>
#include <cmath>

int main() {
    unsigned long long dec = 0;
    std::string s;
    
    std::cout << "Input binary number: ";
    std::getline(std::cin, s);

    for (unsigned short i = 0; i < s.length(); i++) {
        if ((s[i] != '0') && (s[i] != '1')) {
            std::cout << "ERR : Not Binary!" << std::endl;
            exit(1);
        }
    }

    if (s.length() >= 53) {
        std::cout << "ERR : 범위 ERR(52자리까지만 정상 작동하게 설계되었습니다 :)" << std::endl;
        exit(1);
    }
    
    for (int i = s.length(); i >= 0; --i) {
        if (s[i-1] == '1') {
            dec += pow(2, s.length()-i);
        }
    }
    std::cout << "Decimal: " << std::dec << dec << std::endl << "Hexadecimal: " << std::hex << dec << std::endl << std::endl;

    return 0;
}