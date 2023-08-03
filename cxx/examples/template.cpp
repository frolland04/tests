#include <cmath>
#include <cstdio>
#include <fstream>
#include <functional>
#include <iostream>
#include <optional>
#include <string>
#include <tuple>
#include <type_traits>

template <typename T>
struct C {
    T elt;
    void print() { std::cout << elt << std::endl; }
};

template <class T>
void print(const T & elt) { std::cout << elt << std::endl; }

template <typename T> T v;

int main()
{
    C<int> ci;
    ci.elt = 14;
    ci.print();

    C<std::string> cs;
    cs.elt = "Hello World!";
    cs.print();

    int j{28};
    print(j);

    v<int> = 100;
    v<std::string> = "Yes";
    print(v<int>);
    print(v<std::string>);

    return 0;
}
