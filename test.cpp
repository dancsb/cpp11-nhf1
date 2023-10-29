#include <iostream>
#include <cassert>
#include <cstring>

#include "mystring.h"

int main() {
    MyString empty;
    assert(empty.get_size() == 0);
    assert(strcmp(empty.get_data(), "") == 0);

    MyString s1{"Hello "};
    assert(s1.get_size() == 6);
    assert(strcmp(s1.get_data(), "Hello ") == 0);
    MyString s2{"World!"};
    MyString s3{s1 + s2};
    assert(s3.get_size() == 12);
    assert(strcmp(s3.get_data(), "Hello World!") == 0);
    std::cout << s3 << std::endl;

    {
        MyString copy1, copy2, copy3;
        copy1 = copy2 = copy3 = s3;
        assert(copy1.get_size() == 12);
        assert(strcmp(copy1.get_data(), "Hello World!") == 0);
        assert(copy2.get_size() == 12);
        assert(strcmp(copy2.get_data(), "Hello World!") == 0);
        assert(copy3.get_size() == 12);
        assert(strcmp(copy3.get_data(), "Hello World!") == 0);

        copy2 += "!!!";
        assert(copy1.get_size() == 12);
        assert(strcmp(copy1.get_data(), "Hello World!") == 0);
        assert(copy2.get_size() == 15);
        assert(strcmp(copy2.get_data(), "Hello World!!!!") == 0);
        assert(copy3.get_size() == 12);
        assert(strcmp(copy3.get_data(), "Hello World!") == 0);
    }

    {
        MyString hw{MyString{"Hello "} + "World!"};
        for (size_t i = 0; i < s3.get_size(); ++i) {
            assert(hw[i] == s3[i]);
        }
    }

    {
        MyString h{"Hell"};
        h += 'o';
        h += " World!";
        h += MyString("!!!");
        assert(h.get_size() == 15);
        assert(strcmp(h.get_data(), "Hello World!!!!") == 0);
    }

    {
        MyString hw{s3};
        hw[4] = ' ';
        assert(hw.get_size() == 12);
        assert(strcmp(hw.get_data(), "Hell  World!") == 0);
    }

    std::cout << "All test passed" << std::endl;
    return 0;
}
