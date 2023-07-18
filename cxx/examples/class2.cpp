#include <cstdio>
#include <iostream>
#include <optional>
#include <string>
#include <tuple>
#include <type_traits>
#include <functional>

struct S
{
    int a{0};
    void f() { return; }
};

class C
{
public:
    int a{0};
    void f() { return; }

private:
    int c{0};
    void g() { return; }
    // int a(); // error, ambiguous
    void g(int) { return; } // OK, overloading
};

int main ()
{  
    S s;
    int b1{s.a};
    s.f();

    C cc;
    int b2{cc.a};
    // int b3{cc.c}; // error, private
    cc.f();
    // cc.g(); // error, private

    return 0;
}