//
// Created by xrandx on 2020/12/17 0017.
//

#include "str.h"

size_t len(const char *c_str) {
    const char *eos = c_str;
    while (*eos++)
        ;
    return (eos - c_str - 1);
}

char *copy(char *des, const char *src) {
    char *address = des;
    while ((*des++ = *src++))
        ;
    return address;
}


str::str(const char *c_str) {
    if (c_str) {
        size_t len_t = len(c_str) + 1;
        this->src = new char[len_t];
        copy(this->src, c_str);
    } else {
        this->src = new char[1];
        *this->src = '\0';
    }
}


char *str::c_str() const {
    return this->src;
}

str::~str() {
    delete[] this->src;
}

str::str(const str &string) {
    size_t len_t = len(string.src) + 1;
    this->src = new char[len_t];
    copy(this->src, string.src);
}

str &str::operator=(const str &string) {
    if (this == &string) {
        return *this;
    }
    size_t len_t = len(string.src) + 1;
    this->src = new char[len_t];
    copy(this->src, string.src);
    return *this;
}


str str::operator+(const str &string) {
    size_t front = len(this->src);
    size_t len_t = front + len(string.src) + 1;
    char *new_string = new char[len_t];
    copy(new_string, this->src);
    copy(new_string + front, string.src);
    return str(new_string);
}

str &str::operator=(const char *string) {
    size_t len_t = len(string) + 1;
    this->src = new char[len_t];
    copy(this->src, string);
    return *this;
}


str str::operator*(const int &times) {
    size_t len_t = len(this->src);
    size_t new_len = len_t * times;
    char *new_string = new char[new_len + 1];
    for (size_t i = 0; i != times; i++) {
        copy(new_string + i * len_t, this->src);
    }

    return str(new_string);
}

str::str(int integer) {
    std::vector<char> v;
    int negative_cnt = 0;

    if (integer < 0) {
        negative_cnt++;
        integer = -integer;
    }

    while (integer != 0) {
        v.push_back(integer % 10 + '0');
        integer /= 10;
    }

    if (negative_cnt > 0) {
        v.push_back('-');
    }

    char *new_string = new char[v.size() + 1 + negative_cnt];
    size_t idx = 0;

    for (auto i = v.end() - 1; i != v.begin() - 1; --i) {
        new_string[idx++] = *i;
    }
    new_string[idx] = '\0';
    this->src = new_string;
}

void str::replace(const char *dst, const char *rep) {
    size_t replace_len = len(rep);
    size_t destination_len = len(dst);
    if (replace_len == 1 && destination_len == 1) {
        for (size_t i = 0; i != len(this->src); i++) {
            if (this->src[i] == dst[0]) {
                this->src[i] = rep[0];
            }
        }
    } else {
        int next[destination_len];
        next[0] = -1;
    }
}


str operator*(const int &times, str &rhs) {
    return rhs * times;
}
