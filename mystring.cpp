#include <cstring>

#include "mystring.h"

MyString::StringValue::StringValue(const char * s) {
    size = strlen(s);
    data = new char[size + 1];
    strcpy(data, s);
}

MyString::StringValue::StringValue(const MyString::StringValue &other) {
    size = other.size;
    data = new char[size + 1];
    strcpy(data, other.data);
}

MyString::StringValue MyString::StringValue::operator+=(const char c) {
    char *new_data = new char[size + 2];
    strcpy(new_data, data);
    new_data[size] = c;
    new_data[size + 1] = '\0';
    delete[] data;
    data = new_data;
    ++size;
    return *this;
}

MyString::StringValue MyString::StringValue::operator+=(const char * s) {
    char *new_data = new char[size + strlen(s) + 1];
    strcpy(new_data, data);
    strcat(new_data, s);
    delete[] data;
    data = new_data;
    size += strlen(s);
    return *this;
}

char & MyString::StringValue::operator[](int index) {
    return data[index];
}

const char & MyString::StringValue::operator[](int index) const {
    return data[index];
}

size_t MyString::StringValue::get_size() const {
    return size;
}

const char * MyString::StringValue::get_data() const {
    return data;
}

MyString::StringValue::~StringValue() {
    delete[] data;
}

MyString::MyString() {
    value = new StringValue("");
}

MyString::MyString(const char * s) {
    value = new StringValue(s);
}

MyString::MyString(const MyString &other) {
    value = other.value;
    ++value->ref_count;
}

MyString::MyString(MyString &&other) noexcept {
    value = other.value;
    other.value = nullptr;
}

MyString & MyString::operator=(const char * s) {
    if (--value->ref_count == 0) {
        delete value;
    }
    value = new StringValue(s);
    return *this;
}

MyString & MyString::operator=(const MyString &other) {
    if (this == &other) {
        return *this;
    }
    if (--value->ref_count == 0) {
        delete value;
    }
    value = other.value;
    ++value->ref_count;
    return *this;
}

MyString MyString::operator+(const char c) const {
    return MyString(*this) += c;
}

MyString MyString::operator+(const char * s) const {
    return MyString(*this) += s;
}

MyString MyString::operator+(const MyString &other) const {
    return MyString(*this) += other;
}

MyString & MyString::operator+=(const char c) {
    if (value->ref_count > 1) {
        --value->ref_count;
        value = new StringValue(*value);
    }
    *value += c;
    return *this;
}

MyString &MyString::operator+=(const char * s){
    if (value->ref_count > 1) {
        --value->ref_count;
        value = new StringValue(*value);
    }
    *value += s;
    return *this;
}

MyString & MyString::operator+=(const MyString &other) {
    if (value->ref_count > 1) {
        --value->ref_count;
        value = new StringValue(*value);
    }
    *value += other.value->get_data();
    return *this;
}

char & MyString::operator[](int index) {
    if (value->ref_count > 1) {
        --value->ref_count;
        value = new StringValue(*value);
    }
    return (*value)[index];
}

const char & MyString::operator[](int index) const {
    return (*value)[index];
}

MyString::~MyString() {
    if (--value->ref_count == 0) {
        delete value;
    }
}

std::ostream & operator<<(std::ostream &os, const MyString &s) {
    return os << s.value->get_data();
}

std::istream & operator>>(std::istream &is, MyString &s) {
    char c;
    while (is.get(c) && c != '\n') {
        s += c;
    }
    return is;
}
