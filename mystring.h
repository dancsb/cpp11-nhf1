#ifndef NHF1_MYSTRING_H
#define NHF1_MYSTRING_H

#include <iostream>

class MyString {
private:
    class StringValue {
    private:
        size_t size;
        char * data;
    public:
        int ref_count = 1;

        explicit StringValue(const char * s);
        StringValue(const StringValue & other);

        StringValue operator+=(char c);
        StringValue operator+=(const char * s);

        char & operator[](int index);
        const char & operator[](int index) const;

        size_t get_size() const;
        const char * get_data() const;

        ~StringValue();
    };

    StringValue * value;

public:
    MyString();
    explicit MyString(const char * s);
    MyString(const MyString & other);
    MyString(MyString && other) noexcept;

    MyString & operator=(const char * s);
    MyString & operator=(const MyString & other);

    MyString operator+(char c) const;
    MyString operator+(const char * s) const;
    MyString operator+(const MyString & other) const;

    MyString & operator+=(char c);
    MyString & operator+=(const char * s);
    MyString & operator+=(const MyString & other);

    char & operator[](int index);
    const char & operator[](int index) const;

    size_t get_size() const;
    const char * get_data() const;

    ~MyString();

    friend std::ostream & operator<<(std::ostream & os, const MyString & s);
    friend std::istream & operator>>(std::istream & is, MyString & s);
};


#endif //NHF1_MYSTRING_H
