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

    void print() const;
    void println() const;

    void clear();
    void reverse();
    const MyString substr(const unsigned short index, const short len);

    void insert(const unsigned short index, const char c);
    void insert(const unsigned short index, const unsigned short count, const char c);
    void insert(const unsigned short index, const char* str);
    void insert(const unsigned short index, const unsigned short count, const char* str);
    void insert(const unsigned short index, MyString& str);
    void insert(const unsigned short index1, MyString& str, const unsigned short index2, const unsigned short count);

    void append(const char c, const unsigned short count);
    void append(const char *str);
    void append(const char *str, const unsigned short count);
    void append(const char *str, const unsigned short index, const unsigned short count);
    void append(const MyString& str);
    void append(const MyString& str, const unsigned short index, const unsigned short count);

    void replace(const unsigned short index, const unsigned short count1, const unsigned short count2, const char c);
    void replace(const unsigned short index, const unsigned short count, const char* str);
    void replace(const unsigned short index, const unsigned short count1, const char* str, const unsigned short count2);
    void replace(const unsigned short index1, const unsigned short count1, const char* str, const unsigned short index2, const unsigned short count2);
    void replace(const unsigned short index, const unsigned short count, MyString& str);
    void replace(const unsigned short index1, const unsigned short count1, MyString& str, const unsigned short index2, const unsigned short count2);

    void assign(const unsigned short count, const char c);
    void assign(const char* str);
    void assign(const char* str, const unsigned short index, const unsigned short count);
    void assign(const MyString& str);
    void assign(const MyString& str, const unsigned short index, const unsigned short count);

    const short compare(const char* str) const;
    const short compare(const MyString& str) const;

    const char at(const unsigned short i) const;
    const char operator[] (const unsigned short i) const;

    MyString& operator=(const char* str);
    MyString& operator=(const MyString& str);
    MyString& operator+=(const char* str);
    MyString& operator+=(const MyString& str);

    friend std::ostream& operator<<(std::ostream& out, const MyString& inputPstr) {
        out << inputPstr.pstr;
        return out;
    }

    private:
    unsigned short length;
    char *pstr = nullptr;
};
