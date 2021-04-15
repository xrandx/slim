//
// Created by kevty on 2020/12/17 0017.
//
#ifndef SLIM_STR_H
#define SLIM_STR_H
#include <iostream>
#include <vector>


class str {
public:
    str(const char *c_str = nullptr);
    str(const str &string);
    explicit str(int integer);
    explicit str(double number);
    ~str();

    str &operator=(const str &string);
    str &operator=(const char *string);
    str operator+(const str &string);
    str operator*(const int &times);
    char *c_str() const;
    void replace(const char dst[2], const char rep[2]);

private:
    char *src;
};

str operator*(const int &times, const str &rhs);


#endif//SLIM_STR_H
