#include <iostream>

class MyString {
private:
    unsigned short length;
    char *pstr = NULL;

public:
    MyString();
    MyString(const char c);
    MyString(const char *s);
    MyString(const MyString& str);
    virtual ~MyString();

    void setString(char *str);
    const char* getString();
    const unsigned short getLength();

    const void print();
    const void println();

    void clear();
    void reverse();
    const MyString substr(unsigned short index, short len);

    void insert(const unsigned short index, const char c);
    void insert(const unsigned short index, const unsigned short count, const char c);
    void insert(const unsigned short index, const char* str);
    // void insert(const unsigned short index, const unsigned short count, const char* str);
    void insert(const unsigned short index, MyString& str);
    // insert(size_type index, const basic_string& str, size_type index_str, size_type count = npos);

    void append(const char c, const unsigned short count);
    void append(const char *str);
    // void append(const char *str, const unsigned short count);
    void append(const char *str, const unsigned short index, const unsigned short count);
    void append(const MyString& str);
    void append(const MyString& str, const unsigned short index, const unsigned short count);

    void replace(const unsigned short index, const unsigned short count1, const unsigned short count2, const char c);
    void replace(const unsigned short index, const unsigned short count, const char* str);
    void replace(const unsigned short index, const unsigned short count1, const char* str, const unsigned short count2);
    // void replace(const unsigned short index1, const unsigned short len1, const char* str, const unsigned short index2, const unsigned short len2);
    void replace(const unsigned short index, const unsigned short count, MyString& str);
    void replace(const unsigned short index1, const unsigned short count1, MyString& str, const unsigned short index2, const unsigned short count2);

    void assign(const unsigned short count, const char c);
    void assign(const char* str);
    void assign(const char* str, const unsigned short index, const unsigned short count);
    void assign(const MyString& str);
    void assign(const MyString& str, const unsigned short index, const unsigned short count);

    const short compare(const char* str);
    // const short compare(const char* str, const unsigned short index, const unsigned short len);
    const short compare(const MyString& str);
    // const short compare(const MyString& str, const unsigned short index, const unsigned short len);

    const char at(const unsigned short i);
    const char operator[] (const unsigned short i);

    MyString& operator=(const char* str);
    MyString& operator=(const MyString& str);
    MyString& operator+=(const char* str);
    MyString& operator+=(const MyString& str);
    // MyString& operator+(const char* str);
    // MyString& operator+(const MyString& str);

    friend std::ostream& operator<<(std::ostream& out, const MyString& inputPstr) {
        out << inputPstr.pstr;
        return out;
    }
};
