// reate a program which calculates binary operations.
// Supported operations: and, or, xor, nor
// 이진 연산을 계산하는 프로그램을 만듭니다.
// 지원되는 연산: and, or, xor, nor


#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    do {
        string input_binary1, input_binary2;
        string OP, Res="";
        int len1, len2;
        // unsigned short dec1 = 0, dec2 = 0;

        cout << "A: ";
        cin >> input_binary1;
        cout << "B: ";
        cin >> input_binary2;
        cout << "OP: ";
        cin >> OP;


        // 문자열을 같은 자리수로 setting
        len1 = input_binary1.length();
        len2 = input_binary2.length();
        if(len1 > len2) {
            for(unsigned short i=0; i<abs(len1) -abs(len2); i++) input_binary2.insert(i, "0");
        } else if (len1 < len2) for(unsigned short i=0; i<abs(len2) -abs(len1); i++) input_binary1.insert(i, "0");


        // // substitution ( binary < - > DEC )
        // for(int i=input_binary1.length(); i>0; i--)
        //     if(input_binary1[i-1] == '1') dec1 += pow(2, input_binary1.length() - i);
        // for(int i=input_binary2.length(); i>0; i--)
        //     if(input_binary2[i-1] == '1') dec2 += pow(2, input_binary2.length() - i);

        
        // OP
        if(OP == "and" || OP == "AND") {
            for(int i=0; i<len1; i++) {
                if(input_binary1[i] == input_binary2[i]) {
                    if(input_binary1[i] == '1') Res+= "1";
                    else Res+= "0";
                } else Res+= "0";
            }
        } else if(OP == "or" || OP == "OR") {
            for(int i=0; i<len1; i++) {
                if(input_binary1[i] == '1' || input_binary2[i] == '1') Res+= "1";
                else Res+= "0";
            }
        } else if(OP == "xor" || OP == "XOR") {
            for(int i=0; i<len1; i++) {
                if(input_binary1[i] == input_binary2[i]) Res+= "0";
                else Res+= "1";
            }
        } else if(OP == "nor" || OP == "NOR") {
            cout << "변수 2개로 nor 연산을 이해하지 못했습니다." << endl;
        } else {
            cout << "OP input error" << endl;
            break;
        }

        cout << endl << endl << "Result: " << Res << endl << endl << endl;
    } while(1);
}