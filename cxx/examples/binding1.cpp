#include <cmath>
#include <cstdio>
#include <fstream>
#include <functional>
#include <iostream>
#include <optional>
#include <string>
#include <tuple>
#include <type_traits>

class X {
public:
    void f() { std::cout << "fX()" << std::endl; }
};

class Y : public X {
public:
    void f() { std::cout << "fY()" << std::endl; }
};

int main()
{
    Y y;
    X& x = y; // "seen" as a X
    x.f();    // calls X::f()
    y.f();    // calls Y::f()

    return 0;
}
