#include <cstdio>
#include <iostream>
#include <optional>
#include <string>
#include <tuple>
#include <type_traits>
#include <functional>

struct S;
class C;
int f(const C &);

class CC
{
    int a{0};
    int b{-1};
};

int main ()
{  
    // S s; // error, ODR-used but undefined.
    // C c;
    // f(c);

    CC cc;   // OK, declared and defined.

    // std::cout << cc.a; // error, declared "private"

    return 0;
}