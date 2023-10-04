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
    virtual void f() /*final*/ =0; //{ std::cout << "fX()" << std::endl; }
};

class Y : public X {
public:
    void f() override { std::cout << "fY()" << std::endl; }
};

int main()
{
    // X obj;    // error, uncreatable "abstract"
    Y y;
    X& x = y; // "seen" as a X
    x.f();    // calls Y::f()
    y.f();    // calls Y::f()

    X* px = &y;
    px->f();  // calls Y::f()
              // using pointer

    return 0;
}
