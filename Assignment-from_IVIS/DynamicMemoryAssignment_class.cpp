#include "DynamicMemoryAssignment.h"

unsigned short myLength(const char* str) {
    unsigned short count;

    if (str[0] == '\0') {
        count = 0;
    } else {   
        while (str[count] != '\0') {
            ++count;
        }
    }

    return count;
}


MyString::MyString() : length(0) {
    pstr = new char[1];
    pstr[0] = '\0';
}

MyString::MyString(const char c) : length(1) {
    pstr = new char[2];
    pstr[0] = c;
    pstr[1] = '\0';
}

MyString::MyString(const char *s) : length(myLength(s)) {
    pstr = new char[length + 1];

    if (length == 0) {
        pstr[0] = '\0';
    } else {            
        for (unsigned short i = 0; i < length; ++i) {
            pstr[i] = s[i];
        }
        pstr[length] = '\0';
    }
}

MyString::MyString(const MyString& str) : length(myLength(str.pstr)) {
    if (this != &str) {
        char *tmp = new char[length + 1];

        for (unsigned short i = 0; i < length; ++i) {
            tmp[i] = str.pstr[i];
        }
        tmp[length] = '\0';

        delete[] pstr;
        pstr = tmp;
    }    
}

MyString::MyString(MyString&& str) {
    length = str.length;
    pstr = str.pstr;
    
    str.pstr = new char[1];
    str.pstr[0] = '\0';
    str.length = 0;
}

MyString::~MyString() {
    delete[] pstr;
    pstr = nullptr;
    length = 0;
}

const void MyString::setString(const char* str) {
    assign(str, 0, myLength(str));
}

const char* MyString::getString() const {
    return pstr;
}

const unsigned short MyString::getLength() const {
    return length;
}

const void MyString::print() const {
    for (unsigned short i = 0; i < length; ++i) {
        std::cout << pstr[i];
    }
}

const void MyString::println() const {
    for (unsigned short i = 0; i < length; ++i) {
        std::cout << pstr[i];
    }

    std::cout << std::endl;
}

const void MyString::clear() {
    delete[] pstr;
    
    pstr = new char[1];
    pstr[0] = '\0';
    length = 0;
}

const void MyString::reverse() const {
    for (unsigned short i = 0; i < (length / 2); ++i) {
        std::swap(pstr[i], pstr[length - 1 - i]);
    }
}


const MyString MyString::substr(const unsigned short index, const short len = -1) const { 
    if (index > length) {
        throw std::out_of_range("ERR: not found index");
    } else {
        MyString tmp(pstr);
        unsigned short tmpLen = (len == -1) ? length : len;

        char* temp = new char[tmpLen + 1];

        for (unsigned short i = 0; i < tmpLen; ++i) {
            temp[i] = pstr[index + i];
        }
        temp[tmpLen] = '\0';

        tmp = temp;
        tmp.length = tmpLen;

        return tmp;
    }   
}


const void MyString::insert(const unsigned short index, const char c) {
    insert(index, 1, c);
}

const void MyString::insert(const unsigned short index, const unsigned short count, const char c) {
    if (index > length) {        
        throw std::out_of_range("ERR: not found index");
    } else {
        char *tmp = new char[length + count + 1];

        memcpy(tmp, pstr, sizeof(char) * index);

        for (unsigned short i = 0; i < count; ++i) {
            tmp[index + i] = c;
        }

        memcpy(tmp + index + count, pstr + index, sizeof(char) * (length - index));
        tmp[length + count] = '\0';

        delete[] pstr;
        pstr = tmp;
        length += count;
    }
}

const void MyString::insert(const unsigned short index, const char* str) {
    insert(index, 0, str);
}

const void MyString::insert(const unsigned short index, const unsigned short count, const char* str) {
    if (str[0] == '\0') {
        std::cout << "ERR: request NULL" << std::endl;
    } else if (index > length) {
        std::cout << "ERR: not found index" << std::endl;
    } else if (count > myLength(str)) {
        std::cout << "ERR: 삽입하고 싶은 문자열의 길이 초과(count" << std::endl;
    } else {
        char *tmp = new char[length + count + 1];
        
        memcpy(tmp, pstr, sizeof(char) * index);
        memcpy(tmp + index, str, sizeof(char) * count);
        memcpy(tmp + index + count, pstr + index, sizeof(char) * (length - index));
        tmp[length + count] = '\0';

        delete[] pstr;
        pstr = tmp;
        length += count;
    }
}

const void MyString::insert(const unsigned short index, const MyString& str) {
    insert(index, str.pstr);
}

const void MyString::insert(const unsigned short index1, const MyString& str, const unsigned short index2,
                            const unsigned short count) {
    if (str.pstr[0] == '\0') {
        std::cout << "ERR: request NULL" << std::endl;
    } else if (index1 > length) {
        std::cout << "ERR: not found index" << std::endl;
    } else if (index2 == 0) {
        insert(index1, count, str.pstr);
    } else if (index2 > str.getLength()) {
        std::cout << "ERR: not found index(&str" << std::endl;
    } else if (count > str.getLength()) {
        std::cout << "ERR: 삽입하고 싶은 문자열의 길이 초과(count" << std::endl;
    } else {
        char *tmp = new char[length + count + 1];
        
        memcpy(tmp, pstr, sizeof(char) * index1);
        memcpy(tmp + index1, str.pstr + index2, sizeof(char) * count);
        memcpy(tmp + index1 + count, pstr + index1, sizeof(char) * (length - index1));
        tmp[length + count] = '\0';

        delete[] pstr;
        pstr = tmp;
        length += count;
    }
}

const void MyString::append(const char c, const unsigned short count) {
    insert(length, count, c);
}

const void MyString::append(const char *str) {
    append(str, 0, myLength(str));
}

const void MyString::append(const char *str, const unsigned short count) {
    append(str, 0, count);
}

const void MyString::append(const char *str, const unsigned short index, const unsigned short count) {
    if (str[0] == '\0') {
        std::cout << "ERR: request NULL" << std::endl;
    } else if (count <= 0) {
        std::cout << "ERR: need to ' count ' > 0" << std::endl;
    } else if (count > myLength(str)) {
        std::cout << "ERR: ' Count ' Over ( 추가를 원하는 문자열의 길이가, 추가를 위해 주어진 문자열의 길이보다 큽니다"
                  << std::endl;
    } else if (index > myLength(str)) {
        std::cout << "ERR: not found index" << std::endl;
    } else {
        char *temp = new char[length + count + 1];

        for (unsigned short i = 0; i < length; ++i) {
            temp[i] = pstr[i];
        }

        for (unsigned short i = 0; i < count; ++i) {
            temp[length + i] = str[index + i];
        }
        temp[(length) + count] = '\0';

        delete[] pstr;
        pstr = temp;
        length += count;
    }    
}

const void MyString::append(const MyString& str) {
    append(str.pstr, 0, str.length); 
}

const void MyString::append(const MyString& str, const unsigned short index, const unsigned short count) {
    append(str.pstr, index, count);
}


const void MyString::replace(const unsigned short index, const unsigned short count1, const unsigned short count2, const char c) {
    if (index > length) {
        std::cout << "ERR: not found index" << std::endl;
    } else if (count1 > length) {
        std::cout << "ERR: 치환 가능한 길이가, 입력한 길이보다 작습니다." << std::endl;        
    } else {
        char *tmp = new char[length - count1 + count2 + 1];

        for (unsigned short i = 0; i < index; ++i) {
            tmp[i] = pstr[i];
        }

        for (unsigned short i = 0; i < count2; ++i) {
            tmp[index + i] = c;
        }

        for (unsigned short i = index; i < length; ++i) {
            tmp[count2 + i] = pstr[count1 + i];
        }
        tmp[length + count2] = '\0';

        delete [] pstr;
        pstr = tmp;
        length = myLength(pstr);
    }
}

const void MyString::replace(const unsigned short index, const unsigned short count, const char* str) {
    replace(index, count, str, 0, myLength(str));
}

const void MyString::replace(const unsigned short index, const unsigned short count1, const char* str,
                             const unsigned short count2) {
    replace(index, count1, str, 0, count2);
}

const void MyString::replace(const unsigned short index1, const unsigned short count1, const char* str,
                             const unsigned short index2, const unsigned short count2) {
    if (str[0] == '\0') {
        std::cout << "ERR: request NULL" << std::endl;
    } else if (index1 > length) {
        std::cout << "ERR: not found index(this" << std::endl;
    } else if (count1 > length) {
        std::cout << "ERR: 치환 가능한 길이가, 치환을 원하는 길이보다 작습니다(count1" << std::endl;
    } else if (count2 > myLength(str)) {
        std::cout << "ERR: 치환 가능한 길이가, 치환을 원하는 길이보다 작습니다(count2" << std::endl;
    } else if (index2 > myLength(str)) {
        std::cout << "ERR: not found index(&str" << std::endl;
    } else {
        char *tmp = new char[length - count1 + count2 + 1];

        for (unsigned short i = 0; i < index1; ++i) {
            tmp[i] = pstr[i];
        }

        for (unsigned short i = 0; i < count2; ++i) {
            tmp[index1 + i] = str[index2 + i];
        }

        for (unsigned short i = index1; i < (length) - count1; ++i) {
            tmp[count2 + i] = pstr[count1 + i];
        }
        tmp[length - count1 + count2] = '\0';

        delete [] pstr;
        pstr = tmp;
        length = myLength(pstr);
    }
}

const void MyString::replace(const unsigned short index, const unsigned short count, const MyString& str) {
    replace(index, count, str.pstr, 0, str.length);
}

const void MyString::replace(const unsigned short index1, const unsigned short count1, const MyString& str,
                             const unsigned short index2, const unsigned short count2) {
    replace(index1, count1, str.pstr, index2, count2);
}


const void MyString::assign(const unsigned short count, const char c) {
    char* tmp = new char[count + 1];

    memset(tmp, c, (sizeof(char) * count));
    tmp[count] = '\0';

    delete[] pstr;
    pstr = tmp;
    length = count;
}

const void MyString::assign(const char* str) {
    assign(str, 0, myLength(str));
}

const void MyString::assign(const char* str, const unsigned short index, const unsigned short count) {
    if (str == nullptr) {
        clear();
    } else {
        char* tmp = new char[count + 1];
        
        for (unsigned short i = 0; i < count; ++i) {
            tmp[i] = str[index + i];
        }
        tmp[count] = '\0';

        delete[] pstr;
        pstr = tmp;
        length = count;
    }    
}

const void MyString::assign(const MyString& str) {
    assign(str.pstr, 0, str.length);
}

const void MyString::assign(const MyString& str, const unsigned short index, const unsigned short count) {
    assign(str.pstr, index, count);
}


const short MyString::compare(const char* str) const {
    short tmp = 0;

    if (pstr == nullptr) {
        std::cout << "ERR: NULL (this->pstr == nullptr" << std::endl;
    } else if (str == nullptr) {
        std::cout << "ERR: request NULL" << std::endl;
    } else {        
        unsigned short i = 0;

        do {
            if ((pstr[i] == '\0') || (str[i] == '\0')) {
            if (pstr[i] == str[i]) {
                tmp = 0;
            } else {
                tmp = (('\0' == pstr[i]) ? -1 : 1);
            }
            break;
        } else if (pstr[i] > str[i]) {
            tmp = 1;
            break;
        } else if (pstr[i] < str[i]) {
            tmp = -1;
            break;
        }

        ++i;
        } while (i);        
    }

    return tmp;
}

const short MyString::compare(const MyString& str) const {
     short tmp = compare(str.pstr);
     return tmp;
}

const char MyString::at(const unsigned short i) const {
    char tmp = '\0';
    
    if (length > i) {
        tmp = pstr[i];
    }

    return tmp;
}

const char MyString::operator[] (const unsigned short i) const {
    return at(i);
}

const MyString& MyString::operator=(const char* str) {
    assign(str, 0, myLength(str));
    
    return *this;
}

const MyString& MyString::operator=(const MyString& str) {
    operator=(str.pstr);
    return *this;
}

const MyString& MyString::operator+=(const char *str) {
    append(str, 0, myLength(str));
    return *this;
}

const MyString& MyString::operator+=(const MyString& str) {
    append(str.pstr, 0, str.length);
    return *this;
}
