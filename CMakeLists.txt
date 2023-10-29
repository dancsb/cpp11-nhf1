cmake_minimum_required(VERSION 3.13)
project(nhf1)

set(CMAKE_CXX_STANDARD 11)
add_compile_options(-Wall -Wextra -Wpedantic -Wdeprecated)

add_executable(nhf1 test.cpp mystring.cpp mystring.h)
