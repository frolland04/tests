#include <cassert>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <functional>
#include <iostream>
#include <optional>
#include <string>
#include <tuple>
#include <type_traits>

int main()
{
    int x{2};    // lvalue
    int& rx{x};  // lvalue reference

    666;    // rvalue
    x + 2;  // rvalue
    int&& rvr1{666};
    int&& rvr2{x + 2};
    // not possible using single &
    rvr2++;
    printf("%d,%d\n", rvr1, rvr2);  // 666, 5

    int i1{666};
    int i2{x + 2};
    // possible using no & at all
    // but lvalue

    printf("%d,%d\n", i1, i2);  // 666, 4

    // Huh, useless ? really ? No ....

    rvr2 = 666;
    printf("%d,%d\n", rvr1, rvr2);  // 666, 666
    // again, not possible using lvalue reference

    rvr2 = x;
    printf("%d,%d\n", rvr1, rvr2);  // 666, 2
    // again, not possible using lvalue reference
    
    return 0;
}