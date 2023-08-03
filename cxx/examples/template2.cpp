#include <cmath>
#include <cstdio>
#include <fstream>
#include <functional>
#include <iostream>
#include <optional>
#include <string>
#include <tuple>
#include <type_traits>

using S = std::string;
struct C {
    template <class T>
    void print(const T& elt) {
        std::cout << elt << std::endl;
    }
};

template <class T>
void print(const T& elt) {
    std::cout << elt << std::endl;
}

void print(const S& s) {
    std::cout << "(S) " << s << std::endl;
}

int main() {
    int j{28};
    print<int>(j); // 28
    print(j);      // 28, ADL + deduction

    S s{"Hello World!"};
    print(s);    // (s) Hello World!
                 // unless you comment out
                 // 'print(S&)'
    print<>(s);  // Hello World!
    print<S>(s); // Hello World!

    // 'C' is NOT class template
    C cc;

    // 'C::print()' is function template
    cc.print(s);  // Hello World!

    return 0;
}
