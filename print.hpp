//
// Created by kevty on 2021/3/24 0024.
//

#ifndef PYSTRING_PRINT_HPP
#define PYSTRING_PRINT_HPP


void print() {}
template<typename T, typename... Types>
void print(const T &firstArg, const Types &...args) {
    std::cout << firstArg << "\n";
    print(args...);
}
template<typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec) {
    os << "{ ";
    for (auto &v : vec)
        os << v << ' ';
    os << "}";
    return os;
}

#endif//PYSTRING_PRINT_HPP
