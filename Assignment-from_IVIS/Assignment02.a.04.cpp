#include <iostream>
#include <string>
#include <cmath>

void checkBinary(std::string &val) {
    for (unsigned short i = 0; i < val.length(); i++) {
        if ((val[i] != '0') && (val[i] != '1')) {
            std::cout << "ERR: 이진수가 아닌 값 입력" << std::endl;
            exit(1);
        }
    }
}

int main() {
    std::string input_binary1;
    std::string input_binary2;
    std::string op;
    std::string res = "";
    int len1;
    int len2;

    std::cout << "A: ";
    std::cin >> input_binary1;
    checkBinary(input_binary1);

    std::cout << "B: ";
    std::cin >> input_binary2;
    checkBinary(input_binary2);


    // 문자열을 같은 자리수로 setting
    len1 = input_binary1.length();
    len2 = input_binary2.length();
    if (len1 > len2) {
        for (unsigned short i = 0; i < (abs(len1) - abs(len2)); ++i) {
            input_binary2.insert(i, "0");
        }
    } else if (len1 < len2) {
        for (unsigned short i = 0; i < (abs(len2) - abs(len1)); ++i) {
            input_binary1.insert(i, "0");
        }
    }
    
    std::cout << "OP: ";
    std::cin >> op;
    

    // OP
    if ((op == "and") || (op == "AND")) {
        for (int i = 0; i < len1; ++i) {
            if (input_binary1[i] == input_binary2[i]) {
                if (input_binary1[i] == '1') {
                    res+= "1";
                } else {
                    res+= "0";
                }
            } else {
                res+= "0";
            }
        }
    } else if ((op == "or") || (op == "OR")) {
        for (int i = 0; i < len1; ++i) {
            if (input_binary1[i] == '1' || input_binary2[i] == '1') {
                res+= "1";
            } else {
                res+= "0";
            }
        }
    } else if ((op == "xor") || (op == "XOR")) {
        for (int i = 0; i < len1; ++i) {
            if (input_binary1[i] == input_binary2[i]) {
                res+= "0";
            } else {
                res+= "1";
            }
        }
    } else if ((op == "nor") || (op == "NOR")) {
        for (int i = 0; i < len1; ++i) {
            if ((input_binary1[i] == '0') && (input_binary2[i] == '0')) {
                res+= "1";
            } else {
                res+= "0";
            }
        }
    } else {
        std::cout << "OP input error" << std::endl;
    }
    std::cout << std::endl << std::endl << "Result: " << res << std::endl << std::endl << std::endl;
}
