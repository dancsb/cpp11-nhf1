#include <iostream>

#include "mystring.h"

int main() {
    MyString s1("Hello");
    MyString s2("World");
    MyString s3("!");
    MyString s(" ");
    MyString e;

    std::cout << s1 << s << s2 << s << s3 << std::endl;

    MyString a;
    std::cout << "Enter a string: ";
    std::cin >> a;
    std::cout << "You entered: " << a << std::endl;
    return 0;
}
