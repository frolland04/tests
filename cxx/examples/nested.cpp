#include <cstdio>
#include <iostream>
#include <optional>
#include <string>
#include <tuple>
#include <type_traits>
#include <functional>


class C
{
public:
    int c{-1};
    int f()  { return s.a + a; }
    int ff() { return s.ff(this); }
    int gg() { return s.gg(&s); }

private:
    struct S {
        int a{10}, b{20};
        int f() { return a; } // S::a
        int ff(C * p) { return p->a + b; }
        int gg(S * p) { return a + b; }
    };

    S s;
    int a{-1};
};

int main ()
{  

    C cc;
    // S s;    // error, undeclared
    // C::S s; // error, private
    printf("%d", cc.f()); // OK: 9

    //printf("%d", cc.a); // error, private
    printf("%d", cc.c); // OK: -1
    printf("%d", cc.ff()); // OK: 19
    printf("%d", cc.gg()); // OK: 30

    return 0;
}