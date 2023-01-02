// Create C++ application that takes binary number as an input and prints it in decimal and hex.
// 이진수를 입력으로 받아 십진수와 16진수로 인쇄하는 C++ 애플리케이션을 만듭니다.


#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string s;
    int dec = 0;

    cout << "Input binary number: ";
    cin >> s;

    for(int i=s.length(); i>0; i--) {
        if(s[i-1] == '1') dec += pow(2, s.length()-i);
    }
    cout << "Decimal: " << dec << endl << "Hexadecimal: " << std::hex << dec << endl;
    
}