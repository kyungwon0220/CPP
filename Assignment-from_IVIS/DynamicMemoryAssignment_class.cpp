#include "DynamicMemoryAssignment.h"

unsigned short myLength(const char* str) {
    unsigned short count = 0;

    while (str[count] != '\0') {
        ++count;
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

    for (unsigned short i = 0; i < length; ++i) {
        pstr[i] = s[i];
    }
    pstr[length] = '\0';
}

MyString::MyString(const MyString& str) : length(myLength(str.pstr)) {
    char *tmp = new char[length + 1];

    for (unsigned short i = 0; i < length; ++i) {
        tmp[i] = str.pstr[i];
    }
    tmp[length] = '\0';

    delete[] pstr;
    pstr = tmp;
}

MyString::MyString(MyString&& str) {
    length = str.length;
    pstr = str.pstr;
    str.pstr = nullptr;
}

MyString::~MyString() {
    delete[] pstr;
    pstr = nullptr;
}

const void MyString::setString(const char* str) {
    length = myLength(str);
    char *tmp = new char[length + 1];

    for (unsigned short i = 0; i < length; ++i) {
        tmp[i] = str[i];
    }
    tmp[length] = '\0';

    delete[] pstr;
    pstr = tmp;
}

const char* MyString::getString() const {
    return pstr;
}

const unsigned short MyString::getLength() const {
    return length;
}

void MyString::print() const {
    for (unsigned short i = 0; i < length; ++i) {
        std::cout << pstr[i];
    }
}

void MyString::println() const {
    for (unsigned short i = 0; i < length; ++i) {
        std::cout << pstr[i];
    }

    std::cout << std::endl;
}

void MyString::clear() {
    delete[] pstr;
    
    pstr = new char[1];
    pstr[0] = '\0';
    length = 0;
}

void MyString::reverse() {
    for (unsigned short i = 0; i < (length / 2); ++i) {
        std::swap(pstr[i], pstr[length - 1 - i]);
    }
}


const MyString MyString::substr(const unsigned short index, const short len = -1) {
    if (index > length) {
        std::cout << "ERR: not found index" << std::endl;
    } else {
        MyString tmp;
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

void MyString::insert(const unsigned short index, const char c) {
    if (index > length + 1) {
        std::cout << "ERR: not found index" << std::endl;
    } else if (c == '\0') {
        std::cout << "ERR: request NULL" << std::endl;
    } else {        
        length++;
        
        char *tmp = new char[length + 1];

        memcpy(tmp, pstr, sizeof(char) * index);
        tmp[index] = c;
        memcpy(tmp + index + 1, pstr+index, sizeof(char) * (length - index));
        tmp[length] = '\0';
        
        delete[] pstr;
        pstr = tmp;
    }
}

void MyString::insert(const unsigned short index, const unsigned short count, const char c) {
    if (index > length) {        
        std::cout << "ERR: not found index" << std::endl;
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

void MyString::insert(const unsigned short index, const char* str) {
    if (index > length) {        
        std::cout << "ERR: not found index" << std::endl;
    } else if (str[0] == '\0') {
        std::cout << "ERR: request NULL" << std::endl;
    } else {
        unsigned short inputLen = myLength(str);
        char *tmp = new char[length + inputLen + 1];
        
        memcpy(tmp, pstr, sizeof(char) * index);
        memcpy(tmp + index, str, sizeof(char) * inputLen);
        memcpy(tmp + index + inputLen, pstr + index, sizeof(char) * (length - index));
        tmp[length + inputLen] = '\0';

        delete[] pstr;
        pstr = tmp;
        length += inputLen;
    }
}

void MyString::insert(const unsigned short index, const unsigned short count, const char* str) {
    if (index > length) {
        std::cout << "ERR: not found index" << std::endl;
    } else if (count > myLength(str)) {
        std::cout << "ERR: 삽입하고 싶은 문자열의 길이 초과(count" << std::endl;
    } else if (str[0] == '\0') {
        std::cout << "ERR: request NULL" << std::endl;
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

void MyString::insert(const unsigned short index, MyString& str) {
    MyString::insert(index, str.pstr);
}

void MyString::insert(const unsigned short index1, MyString& str, const unsigned short index2, const unsigned short count) {
    if (index1 > length) {
        std::cout << "ERR: not found index" << std::endl;
    } else if (index2 > str.getLength()) {
        std::cout << "ERR: not found index(&str" << std::endl;
    } else if (count > str.getLength()) {
        std::cout << "ERR: 삽입하고 싶은 문자열의 길이 초과(count" << std::endl;
    } else if (str.pstr[0] == '\0') {
        std::cout << "ERR: request NULL" << std::endl;
    } else if (index2 == 0) {
        MyString::insert(index1, count, str.pstr);
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

void MyString::append(const char c, const unsigned short count) {
    char *tmp = new char[length + count + 1];

    for (unsigned short i = 0; i < length; ++i) {
        tmp[i] = pstr[i];
    }

    for (unsigned short i = 0; i < count; ++i) {
        tmp[length + i] = c;
    }

    tmp[length + count] = '\0';

    delete[] pstr;
    pstr = tmp;
    length += count;
}

void MyString::append(const char *str) {
    MyString::append(str, 0, myLength(str));
}

void MyString::append(const char *str, const unsigned short count) {
    MyString::append(str, 0, count);
}

void MyString::append(const char *str, const unsigned short index, const unsigned short count) {
    if (count <= 0) {
        std::cout << "ERR: need to ' count ' > 0" << std::endl;
    } else if (count > myLength(str)) {
        std::cout << "ERR: ' Count ' Over ( 추가를 원하는 문자열의 길이가, 추가를 위해 주어진 문자열의 길이보다 큽니다" << std::endl;
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

void MyString::append(const MyString& str) {
    MyString::append(str.pstr, 0, str.length); 
}

void MyString::append(const MyString& str, const unsigned short index, const unsigned short count) {
    MyString::append(str.pstr, index, count);
}


void MyString::replace(const unsigned short index, const unsigned short count1, const unsigned short count2, const char c) {
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

void MyString::replace(const unsigned short index, const unsigned short count, const char* str) {
    MyString::replace(index, count, str, 0, myLength(str));
}

void MyString::replace(const unsigned short index, const unsigned short count1, const char* str, const unsigned short count2) {
    MyString::replace(index, count1, str, 0, count2);
}

void MyString::replace(const unsigned short index1, const unsigned short count1, const char* str, const unsigned short index2, const unsigned short count2) {
    unsigned short inputLen = myLength(str);

    if (index1 > length) {
        std::cout << "ERR: not found index(this" << std::endl;
    } else if (count1 > length) {
        std::cout << "ERR: 치환 가능한 길이가, 치환을 원하는 길이보다 작습니다(count1" << std::endl;
    } else if (count2 > inputLen) {
        std::cout << "ERR: 치환 가능한 길이가, 치환을 원하는 길이보다 작습니다(count2" << std::endl;
    } else if (index2 > inputLen) {
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

void MyString::replace(const unsigned short index, const unsigned short count, MyString& str) {
    MyString::replace(index, count, str.pstr, 0, str.length);
}

void MyString::replace(const unsigned short index1, const unsigned short count1, MyString& str, const unsigned short index2, const unsigned short count2) {
    MyString::replace(index1, count1, str.pstr, index2, count2);
}


void MyString::assign(const unsigned short count, const char c) {
    char* tmp = new char[count + 1];

    memset(tmp, c, (sizeof(char) * count));
    tmp[count] = '\0';

    delete[] pstr;
    pstr = tmp;
    length = count;
}

void MyString::assign(const char* str) {
    MyString::assign(str, 0, myLength(str));
}

void MyString::assign(const char* str, const unsigned short index, const unsigned short count) {
    char* tmp = new char[count + 1];
    
    for (unsigned short i = 0; i < count; ++i) {
        tmp[i] = str[index + i];
    }
    tmp[count] = '\0';

    delete[] pstr;
    pstr = tmp;
    length = count;
}

void MyString::assign(const MyString& str) {
    MyString::assign(str.pstr, 0, str.length);
}

void MyString::assign(const MyString& str, const unsigned short index, const unsigned short count) {
    MyString::assign(str.pstr, index, count);
}


const short MyString::compare(const char* str) const {
    short tmp = 0;
    unsigned short inputLen = myLength(str);
    unsigned short loop = (length  >= inputLen) ? inputLen : length;

    for (unsigned short i = 0; i < loop; ++i) {
        if ((0 == pstr[i]) || (0 == str[i])) {
            if (pstr[i] == str[i]) {
               tmp = 0;
            } else {
               tmp = ((0 == pstr[i]) ? 1 : -1);
            }
            break;
        } else if (pstr[i] > str[i]) {
            tmp = 1;
            break;
        } else if (this->pstr[i] < str[i]) {
            tmp = -1;
            break;
        }
    }

    if ((tmp == 0) && (length < inputLen)) {
        tmp = -1;
    } else if ((tmp == 0) && (length > inputLen)) {
        tmp = 1;
    }

    return tmp;
}

const short MyString::compare(const MyString& str) const {
     short tmp = MyString::compare(str.pstr);
     return tmp;
}

const char MyString::at(const unsigned short i) const {
    char tmp;
    
    if (length < i) {
        tmp = '\0';
    } else {
        tmp = pstr[i];
    }

    return tmp;
}

const char MyString::operator[] (const unsigned short i) const {
    char tmp;
    
    if ((length < i)) {
        tmp = '\0';
    } else {
        tmp = pstr[i];
    }

    return tmp;
}

MyString& MyString::operator=(const char* str) {
    unsigned short inputLen = myLength(str);
    char *tmp = new char[inputLen + 1];

    for (unsigned short i = 0; i < inputLen; ++i) {
        tmp[i] = str[i];
    }
    tmp[inputLen] = '\0';

    delete[] pstr;
    pstr = tmp;
    length = inputLen;
    
    return *this;
}

MyString& MyString::operator=(const MyString& str) {
    MyString::operator=(str.pstr);
    return *this;
}

MyString& MyString::operator+=(const char *str) {
    MyString::append(str, 0, myLength(str));
    return *this;
}

MyString& MyString::operator+=(const MyString& str) {
    MyString::append(str.pstr, 0, str.length);
    return *this;
}
