#include <cmath>
#include <cstdio>
#include <cassert>
#include <fstream>
#include <functional>
#include <iostream>
#include <optional>
#include <string>
#include <tuple>
#include <type_traits>

int f() {
    return 6; // returns an rvalue
}

int y{66};    // lvalue
int & g() {
    return y; // returns an
              // lvalue-reference
}

int main()
{
    // lvalues and rvalues
    int x = 666;   // OK
    int * px = &x; // OK, address-of,
                   // pointer to memory

    // 666 = 999;  // error, lvalue required
    // p = &666;   // error, lvalue required
    x = f();       // OK

    // lvalue references
    x = 666;
    int & rx = x;
    printf("%d", rx); // 666
    rx++;
    g() = 666;        // OK

    // lvalue-to-rvalue
    int z = x;
    z = x + y;

    //int & ri = 10; // error
                     // no conversion
    const int & ri = 10; // OK
    // a very special case, where an lvalue
    // is created for you underneath

    return 0;
}