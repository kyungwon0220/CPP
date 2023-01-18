#include <iostream>
#include <string>

int main() {
    std::string s;
    unsigned short count = 0;

    std::cout << "Input string: ";
    getline(std::cin, s);

    if((s[0] != ' ') && (s[0] != '\0')) {
        count++;
    }

    for (unsigned short i = 1; i < s.length(); ++i) {
	    if ((s[i-1] == ' ') && (s[i] != ' ')) {
            count++;
        }
    }
    std::cout << "number of words: " << count << std::endl;
}
