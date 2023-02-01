#include "DynamicMemoryAssignment.h"

unsigned short myLength(const char* str) {
    unsigned short count = 0;

    while (str[count] != '\0') {
        ++count;
    }

    return count;
}


MyString::MyString() : length(0) {
    this->pstr = new char[1];
    this->pstr[0] = '\0';
}

MyString::MyString(const char c) : length(1) {
    this->pstr = new char[2];
    pstr[0] = c;
    pstr[1] = '\0';
}

MyString::MyString(const char *s) : length(myLength(s)) {
    this->pstr = new char[this->length + 1];

    for (unsigned short i = 0; i < this->length; ++i) {
        this->pstr[i] = s[i];
    }
    pstr[this->length] = '\0';
}

MyString::MyString(const MyString& str) : length(myLength(str.pstr)) {
    char *tmp = new char[this->length + 1];

    for (unsigned short i = 0; i < this->length; ++i) {
        tmp[i] = str.pstr[i];
    }
    tmp[this->length] = '\0';

    delete[] pstr;
    pstr = tmp;
}

MyString::~MyString() {
    delete[] pstr;
    pstr = nullptr;
}

const void MyString::setString(const char* str) {
    this->length = myLength(str);
    char *tmp = new char[this->length + 1];

    for (unsigned short i = 0; i < this->length; ++i) {
        tmp[i] = str[i];
    }
    tmp[this->length] = '\0';

    delete[] pstr;
    pstr = tmp;
}

const char* MyString::getString() const {
    return this->pstr;
}

const unsigned short MyString::getLength() const {
    return this->length;
}

void MyString::print() const {
    for (unsigned short i = 0; i < this->length; ++i) {
        std::cout << this->pstr[i];
    }
}

void MyString::println() const {
    for (unsigned short i = 0; i < this->length; ++i) {
        std::cout << this->pstr[i];
    }

    std::cout << std::endl;
}

void MyString::clear() {
    delete[] pstr;
    
    pstr = new char[1];
    pstr[0] = '\0';
    this->length = 0;
}

void MyString::reverse() {
    for (unsigned short i = 0; i < (this->length / 2); ++i) {
        std::swap(this->pstr[i], this->pstr[this->length - 1 - i]);
    }
}


const MyString MyString::substr(const unsigned short index, const short len = -1) {
    if (index > this->length) {
        std::cout << "ERR: not found index" << std::endl;
    } else {
        MyString tmp;
        unsigned short tmpLen = (len == -1) ? this->length : len;

        char* temp = new char[tmpLen + 1];

        for (unsigned short i = 0; i < tmpLen; ++i) {
            temp[i] = this->pstr[index + i];
        }
        temp[tmpLen] = '\0';

        tmp = temp;
        tmp.length = tmpLen;

        return tmp;
    }
}

void MyString::insert(const unsigned short index, const char c) {
    if (index > this->length + 1) {
        std::cout << "ERR: not found index" << std::endl;
    } else if (c == '\0') {
        std::cout << "ERR: request NULL" << std::endl;
    } else {        
        this->length++;
        
        char *tmp = new char[this->length + 1];

        memcpy(tmp, this->pstr, sizeof(char) * index);
        tmp[index] = c;
        memcpy(tmp + index + 1, this->pstr+index, sizeof(char) * (this->length - index));
        tmp[this->length] = '\0';
        
        delete[] pstr;
        pstr = tmp;
    }
}

void MyString::insert(const unsigned short index, const unsigned short count, const char c) {
    if (index > this->length) {        
        std::cout << "ERR: not found index" << std::endl;
    } else {
        char *tmp = new char[this->length + count + 1];

        memcpy(tmp, this->pstr, sizeof(char) * index);

        for (unsigned short i = 0; i < count; ++i) {
            tmp[index + i] = c;
        }

        memcpy(tmp + index + count, this->pstr + index, sizeof(char) * (this->length - index));
        tmp[this->length + count] = '\0';

        delete[] pstr;
        pstr = tmp;
        this->length += count;
    }
}

void MyString::insert(const unsigned short index, const char* str) {
    if (index > this->length) {        
        std::cout << "ERR: not found index" << std::endl;
    } else if (str[0] == '\0') {
        std::cout << "ERR: request NULL" << std::endl;
    } else {
        unsigned short inputLen = myLength(str);
        char *tmp = new char[this->length + inputLen + 1];
        
        memcpy(tmp, this->pstr, sizeof(char) * index);
        memcpy(tmp + index, str, sizeof(char) * inputLen);
        memcpy(tmp + index + inputLen, this->pstr + index, sizeof(char) * (this->length - index));
        tmp[this->length + inputLen] = '\0';

        delete[] pstr;
        pstr = tmp;
        this->length += inputLen;
    }
}

void MyString::insert(const unsigned short index, const unsigned short count, const char* str) {
    if (index > this->length) {
        std::cout << "ERR: not found index" << std::endl;
    } else if (count > myLength(str)) {
        std::cout << "ERR: 삽입하고 싶은 문자열의 길이 초과(count" << std::endl;
    } else if (str[0] == '\0') {
        std::cout << "ERR: request NULL" << std::endl;
    } else {
        char *tmp = new char[this->length + count + 1];
        
        memcpy(tmp, this->pstr, sizeof(char) * index);
        memcpy(tmp + index, str, sizeof(char) * count);
        memcpy(tmp + index + count, this->pstr + index, sizeof(char) * (this->length - index));
        tmp[this->length + count] = '\0';

        delete[] pstr;
        pstr = tmp;
        this->length += count;
    }
}

void MyString::insert(const unsigned short index, MyString& str) {
    if (index > this->length) {        
        std::cout << "ERR: not found index" << std::endl;
    } else if (str[0] == '\0') {
        std::cout << "ERR: request NULL" << std::endl;
    } else {
        unsigned short inputLen = myLength(str.pstr);
        char *tmp = new char[this->length + inputLen + 1];
        
        memcpy(tmp, this->pstr, sizeof(char) * index);
        memcpy(tmp + index, str.pstr, sizeof(char) * inputLen);
        memcpy(tmp + index + inputLen, this->pstr + index, sizeof(char) * (this->length - index));
        tmp[this->length + inputLen] = '\0';

        delete[] pstr;
        pstr = tmp;
        this->length += inputLen;
    }
}

void MyString::insert(const unsigned short index1, MyString& str, const unsigned short index2, const unsigned short count) {
    if (index1 > this->length) {
        std::cout << "ERR: not found index" << std::endl;
    } else if (index2 > str.getLength()) {
        std::cout << "ERR: not found index(&str" << std::endl;
    } else if (count > str.getLength()) {
        std::cout << "ERR: 삽입하고 싶은 문자열의 길이 초과(count" << std::endl;
    } else if (str.pstr[0] == '\0') {
        std::cout << "ERR: request NULL" << std::endl;
    } else {
        char *tmp = new char[this->length + count + 1];
        
        memcpy(tmp, this->pstr, sizeof(char) * index1);
        memcpy(tmp + index1, str.pstr + index2, sizeof(char) * count);
        memcpy(tmp + index1 + count, this->pstr + index1, sizeof(char) * (this->length - index1));
        tmp[this->length + count] = '\0';

        delete[] pstr;
        pstr = tmp;
        this->length += count;
    }
}

void MyString::append(const char c, const unsigned short count) {
    char *tmp = new char[this->length + count + 1];

    for (unsigned short i = 0; i < this->length; ++i) {
        tmp[i] = this->pstr[i];
    }

    for (unsigned short i = 0; i < count; ++i) {
        tmp[this->length + i] = c;
    }

    tmp[this->length + count] = '\0';

    delete[] pstr;
    pstr = tmp;
    this->length += count;
}

void MyString::append(const char *str) {
    unsigned short inputLen = myLength(str);

    char *tmp = new char[this->length + inputLen + 1];
    
    for (unsigned short i = 0; i < this->length; ++i) {
        tmp[i] = this->pstr[i];
    }
    
    for (unsigned short i = 0; i < myLength(str); ++i) {
        tmp[this->length + i] = str[i];
    }
     tmp[this->length + inputLen] = '\0';

     delete[] pstr;
     pstr = tmp;
     this->length += inputLen;
}

void MyString::append(const char *str, const unsigned short count) {
    if (count > myLength(str)) {
        std::cout << "ERR: 치환 가능한 길이가, 입력한 문자열의 길이보다 작습니다(count" << std::endl;
    } else {
        char *tmp = new char[this->length + count + 1];
        
        for (unsigned short i = 0; i < this->length; ++i) {
            tmp[i] = this->pstr[i];
        }
        
        for (unsigned short i = 0; i < count; ++i) {
            tmp[this->length + i] = str[i];
        }
        tmp[this->length + count] = '\0';

        delete[] pstr;
        pstr = tmp;
        this->length += count;
    }
}

void MyString::append(const char *str, const unsigned short index, const unsigned short count) {
    if (count <= 0) {
        std::cout << "ERR: need to ' count ' > 0" << std::endl;
    } else if (index > myLength(str)) {
        std::cout << "ERR: not found index" << std::endl;
    } else {
        char *temp = new char[this->length + count + 1];

        for (unsigned short i = 0; i < this->length; ++i) {
            temp[i] = this->pstr[i];
        }

        for (unsigned short i = 0; i < count; ++i) {
            temp[this->length + i] = str[index + i];
        }
        temp[(this->length) + count] = '\0';

        delete[] pstr;
        pstr = temp;
        this->length += count;
    }    
}

void MyString::append(const MyString& str) {
    char *tmp = new char[this->length + str.length + 1];

    for (unsigned short i = 0; i < this->length; ++i) {
        tmp[i] = this->pstr[i];
    }

    for (unsigned short i = 0; i < str.length; ++i) {
        tmp[this->length + i] = str.pstr[i];
    }
    tmp[this->length + str.length] = '\0';

    delete[] pstr;
    pstr = tmp;
    this->length += str.length;   
}

void MyString::append(const MyString& str, const unsigned short index, const unsigned short count) {
    if (count <= 0) {
        std::cout << "ERR: need to ' count ' > 0" << std::endl;
    } else if (index > myLength(str.pstr)) {
        std::cout << "ERR: not found index" << std::endl;
    } else {
        char *tmp = new char[this->length + count + 1];

        for (unsigned short i = 0; i < this->length; ++i) {
            tmp[i] = this->pstr[i];
        }

        for (unsigned short i = 0; i < count; ++i) {
            tmp[this->length + i] = str.pstr[index + i];
        }
        tmp[this->length + count] = '\0';

        delete[] pstr;
        pstr = tmp;
        this->length += count;
    }    
}


void MyString::replace(const unsigned short index, const unsigned short count1, const unsigned short count2, const char c) {
    if (index > this->length) {
        std::cout << "ERR: not found index" << std::endl;
    } else if (count1 > this->length) {
        std::cout << "ERR: 치환 가능한 길이가, 입력한 길이보다 작습니다." << std::endl;        
    } else {
        char *tmp = new char[this->length - count1 + count2 + 1];

        for (unsigned short i = 0; i < index; ++i) {
            tmp[i] = this->pstr[i];
        }

        for (unsigned short i = 0; i < count2; ++i) {
            tmp[index + i] = c;
        }

        for (unsigned short i = index; i < this->length; ++i) {
            tmp[count2 + i] = this->pstr[count1 + i];
        }
        tmp[this->length + count2] = '\0';

        delete [] this->pstr;
        this->pstr = tmp;
        this->length = myLength(this->pstr);
    }
}

void MyString::replace(const unsigned short index, const unsigned short count, const char* str) {
    if (index > this->length) {
        std::cout << "ERR: not found index" << std::endl;
    } else if (count > this->length) {
        std::cout << "ERR: 치환 가능한 길이가, 입력한 길이보다 작습니다." << std::endl;
    } else {
        unsigned short inputLen = myLength(str);
        char *tmp = new char[this->length - count + inputLen + 1];

        for (unsigned short i = 0; i < index; ++i) {
            tmp[i] = this->pstr[i];
        }

        for (unsigned short i = 0; i < inputLen; ++i) {
            tmp[index + i] = str[i];
        }

        for (unsigned short i = index; i < (this->length) - count; ++i) {
            tmp[inputLen + i] = this->pstr[count + i];
        }
        tmp[this->length - count + inputLen] = '\0';

        delete [] this->pstr;
        this->pstr = tmp;
        this->length = myLength(this->pstr);
    }
}

void MyString::replace(const unsigned short index, const unsigned short count1, const char* str, const unsigned short count2) {
    if (index > this->length) {
        std::cout << "ERR: not found index" << std::endl;
    } else if (count1 > this->length) {
        std::cout << "ERR: 치환 가능한 길이가, 입력한 길이보다 작습니다(count1" << std::endl;
    } else if (count2 > myLength(str)) {
        std::cout << "ERR: 치환을 원하는 길이가, 치환을 원하는 문자열의 길이보다 작습니다(count2" << std::endl;
    } else {
        char *tmp = new char[this->length - count1 + count2 + 1];

        for (unsigned short i = 0; i < index; ++i) {
            tmp[i] = this->pstr[i];
        }

        for (unsigned short i = 0; i < count2; ++i) {
            tmp[index + i] = str[i];
        }

        for (unsigned short i = index; i < this->length; ++i) {
            tmp[count2 + i] = this->pstr[count1 + i];
        }
        tmp[this->length - count1 + count2] = '\0';

        delete [] this->pstr;
        this->pstr = tmp;
        this->length = myLength(this->pstr);
    }
}

void MyString::replace(const unsigned short index1, const unsigned short count1, const char* str, const unsigned short index2, const unsigned short count2) {
    unsigned short inputLen = myLength(str);

    if (index1 > this->length) {
        std::cout << "ERR: not found index(this" << std::endl;
    } else if (count1 > this->length) {
        std::cout << "ERR: 치환 가능한 길이가, 입력한 길이보다 작습니다(count1" << std::endl;
    } else if (index2 > inputLen) {
        std::cout << "ERR: not found index(&str" << std::endl;
    } else {
        char *tmp = new char[this->length - count1 + count2 + 1];

        for (unsigned short i = 0; i < index1; ++i) {
            tmp[i] = this->pstr[i];
        }

        for (unsigned short i = 0; i < count2; ++i) {
            tmp[index1 + i] = str[index2 + i];
        }

        for (unsigned short i = index1; i < (this->length) - count1; ++i) {
            tmp[count2 + i] = this->pstr[count1 + i];
        }
        tmp[this->length - count1 + count2] = '\0';

        delete [] this->pstr;
        this->pstr = tmp;
        this->length = myLength(this->pstr);
    }
}

void MyString::replace(const unsigned short index, const unsigned short count, MyString& str) {
    if (index > this->length) {
        std::cout << "ERR: not found index" << std::endl;
    } else if (count > this->length) {
        std::cout << "ERR: 치환 가능한 길이가, 입력한 길이보다 작습니다." << std::endl;
    } else {
        unsigned short inputLen = str.length;
        char *tmp = new char[this->length - count + inputLen + 1];

        for (unsigned short i = 0; i < index; ++i) {
            tmp[i] = this->pstr[i];
        }

        for (unsigned short i = 0; i < inputLen; ++i) {
            tmp[index + i] = str.pstr[i];
        }

        for (unsigned short i = index; i < (this->length) - count; ++i) {
            tmp[inputLen + i] = this->pstr[count + i];
        }
        tmp[this->length - count + inputLen] = '\0';

        delete [] this->pstr;
        this->pstr = tmp;
        this->length = myLength(this->pstr);
    }
}

void MyString::replace(const unsigned short index1, const unsigned short count1, MyString& str, const unsigned short index2, const unsigned short count2) {
    if (index1 > this->length) {
        std::cout << "ERR: not found index(this" << std::endl;
    } else if (count1 > this->length) {
        std::cout << "ERR: 치환 가능한 길이가, 입력한 길이보다 작습니다(count1" << std::endl;
    } else if (index2 > str.getLength()) {
        std::cout << "ERR: not found index(&str" << std::endl;
    } else {
        char *tmp = new char[this->length - count1 + count2 + 1];

        for (unsigned short i = 0; i < index1; ++i) {
            tmp[i] = this->pstr[i];
        }

        for (unsigned short i = 0; i < count2; ++i) {
            tmp[index1 + i] = *(str.getString() + index2 + i);
        }

        for (unsigned short i = index1; i < (this->length) - count1; ++i) {
            tmp[count2 + i] = this->pstr[count1 + i];
        }
        tmp[this->length - count1 + count2] = '\0';

        delete [] this->pstr;
        this->pstr = tmp;
        this->length = myLength(this->pstr);
    }
}


void MyString::assign(const unsigned short count, const char c) {
    char* tmp = new char[count + 1];

    for (unsigned short i = 0; i < count; ++i) {
        tmp[i] = c;
    }
    tmp[count] = '\0';

    delete[] pstr;
    pstr = tmp;
    this->length = count;
}

void MyString::assign(const char* str) {
    unsigned short inputLen = myLength(str);
    char* tmp = new char[inputLen + 1];

    for (unsigned short i = 0; i < inputLen; ++i) {
        tmp[i] = str[i];
    }
    tmp[inputLen] = '\0';

    delete[] pstr;
    pstr = tmp;
    this->length = inputLen;
}

void MyString::assign(const char* str, const unsigned short index, const unsigned short count) {
    char* tmp = new char[count + 1];
    
    for (unsigned short i = 0; i < count; ++i) {
        tmp[i] = str[index + i];
    }
    tmp[count] = '\0';

    delete[] pstr;
    pstr = tmp;
    this->length = count;
}

void MyString::assign(const MyString& str) {
    unsigned short inputLen = myLength(str.pstr);

    char* tmp = new char[inputLen + 1];
    
    for (unsigned short i = 0; i < inputLen; ++i) {
        tmp[i] = str.pstr[i];
    }
    tmp[inputLen] = '\0';

    delete[] pstr;
    pstr = tmp;
    this->length = inputLen;
}

void MyString::assign(const MyString& str, const unsigned short index, const unsigned short count) {
    char* tmp = new char[count + 1];
    
    for (unsigned short i = 0; i < count; ++i) {
        tmp[i] = str.pstr[index + i];
    }
    tmp[count] = '\0';

    delete[] pstr;
    pstr = tmp;
    this->length = count;
}


const short MyString::compare(const char* str) {
    short tmp = 0;
    unsigned short inputLen = myLength(str);
    unsigned short loop = (this->length  >= inputLen) ? inputLen : this->length;

    for (unsigned short i = 0; i < loop; ++i) {
        if (this->pstr[i] > str[i]) {
            tmp = 1;
            break;
        } else if (this->pstr[i] < str[i]) {
            tmp = -1;
            break;
        } else {
            continue;
        }
    }

    if ((tmp == 0) && (this->length < inputLen)) {
        tmp = -1;
    } else if ((tmp == 0) && (this->length > inputLen)) {
        tmp = 1;
    }

    return tmp;
}

const short MyString::compare(const MyString& str) {
     short tmp = 0;
        unsigned short inputLen = myLength(str.pstr);
        unsigned short loop = (this->length  >= inputLen) ? inputLen : this->length;

        for (unsigned short i = 0; i < loop; ++i) {
            if (this->pstr[i] > str.pstr[i]) {
                tmp = 1;
                break;
            } else if (this->pstr[i] < str.pstr[i]) {
                tmp = -1;
                break;
            } else {
                continue;
            }
        }

        if ((tmp == 0) && (this->length < inputLen)) {
            tmp = -1;
        } else if ((tmp == 0) && (this->length > inputLen)) {
            tmp = 1;
        }

        return tmp;
}

const char MyString::at(const unsigned short i) {
    char tmp;
    
    if (this->length < i) {
        tmp = '\0';
    } else {
        tmp = this->pstr[i];
    }

    return tmp;
}

const char MyString::operator[] (const unsigned short i) {
    char tmp;
    
    if ((this->length < i)) {
        tmp = '\0';
    } else {
        tmp = this->pstr[i];
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
    this->length = inputLen;
    
    return *this;
}

MyString& MyString::operator=(const MyString& str) {
    unsigned short inputLen = myLength(str.pstr);
    char *tmp = new char[inputLen + 1];

    for (unsigned short i = 0; i < inputLen; ++i) {
        tmp[i] = str.pstr[i];
    }
    tmp[inputLen] = '\0';

    delete[] pstr;
    pstr = tmp;
    this->length = inputLen;
    
    return *this;
}

MyString& MyString::operator+=(const char *str) {
    unsigned short inputLen = myLength(str);
    char *tmp = new char[this->length + inputLen + 1];

    for (unsigned short i = 0; i < this->length; ++i) {
        tmp[i] = this->pstr[i];
    }

    for (unsigned short i = 0; i < inputLen; ++i) {
        tmp[this->length + i] = str[i];
    }
    tmp[this->length + inputLen] = '\0';

    delete[] pstr;
    pstr = tmp;
    this->length += inputLen;
    
    return *this;
}

MyString& MyString::operator+=(const MyString& str) {
    unsigned short inputLen = myLength(str.pstr);
    char *tmp = new char[this->length + inputLen + 1];

    for (unsigned short i = 0; i < this->length; ++i) {
        tmp[i] = this->pstr[i];
    }

    for (unsigned short i = 0; i < inputLen; ++i) {
        tmp[this->length + i] = str.pstr[i];
    }
    tmp[this->length + inputLen] = '\0';

    delete[] pstr;
    pstr = tmp;
    this->length += inputLen;
    
    return *this;
}
