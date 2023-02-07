#ifndef _INCLUDE_
#define _INCLUDE_
#include <iostream>
#include <cstring>
#endif // _INCLUDE_

class MyString {
public:
    MyString();
    explicit MyString(const char c);
    explicit MyString(const char *s);
    MyString(const MyString& str);
    MyString(MyString&& str);
    virtual ~MyString();

    const void setString(const char *str);
    const char* getString() const;
    const unsigned short getLength() const;

    const void print() const;
    const void println() const;

    const void clear();
    const void reverse() const;
    const MyString substr(const unsigned short index, const short len) const;

    const void insert(const unsigned short index, const char c);
    const void insert(const unsigned short index, const unsigned short count, const char c);
    const void insert(const unsigned short index, const char* str);
    const void insert(const unsigned short index, const unsigned short count, const char* str);
    const void insert(const unsigned short index, const MyString& str);
    const void insert(const unsigned short index1, const MyString& str, const unsigned short index2, const unsigned short count);

    const void append(const char c, const unsigned short count);
    const void append(const char *str);
    const void append(const char *str, const unsigned short count);
    const void append(const char *str, const unsigned short index, const unsigned short count);
    const void append(const MyString& str);
    const void append(const MyString& str, const unsigned short index, const unsigned short count);

    const void replace(const unsigned short index, const unsigned short count1, const unsigned short count2, const char c);
    const void replace(const unsigned short index, const unsigned short count, const char* str);
    const void replace(const unsigned short index, const unsigned short count1, const char* str, const unsigned short count2);
    const void replace(const unsigned short index1, const unsigned short count1, const char* str, const unsigned short index2, const unsigned short count2);
    const void replace(const unsigned short index, const unsigned short count, const MyString& str);
    const void replace(const unsigned short index1, const unsigned short count1, const MyString& str, const unsigned short index2, const unsigned short count2);

    const void assign(const unsigned short count, const char c);
    const void assign(const char* str);
    const void assign(const char* str, const unsigned short index, const unsigned short count);
    const void assign(const MyString& str);
    const void assign(const MyString& str, const unsigned short index, const unsigned short count);

    const short compare(const char* str) const;
    const short compare(const MyString& str) const;

    const char at(const unsigned short i) const;
    const char operator[] (const unsigned short i) const;

    const MyString& operator=(const char* str);
    const MyString& operator=(const MyString& str);
    const MyString& operator+=(const char* str);
    const MyString& operator+=(const MyString& str);

    friend std::ostream& operator<<(std::ostream& out, const MyString& inputPstr) {
        out << inputPstr.pstr;
        return out;
    }

    MyString& operator=(MyString&& str) {
        pstr = str.pstr;
        length = str.length;
        str.pstr = nullptr;
        return *this;
    }

    private:
    unsigned short length = 0;
    char *pstr = nullptr;
};
