// Write a C++ program to count all the words in a string provided by user.
// 사용자가 제공한 문자열의 모든 단어를 세는 C++ 프로그램을 작성하십시오.


#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    unsigned short count = 1;

    cout << "Input string: ";
    getline(cin, s);

    for(unsigned short i=0; i<s.length(); i++)
        if(s[i] == ' ') count++;
    
    cout << "number of words: " << count << endl;

}