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
    int fa()  { return a; }
    int ff()  { return fc() + a; }
    // ^^^ access everything internally

private:
    int a{-2};
    int fc()  { return c; }
    // ^^^ not callable from "outside"
};

int main ()
{ 
    C cc1, cc2;
    std::cout << cc1.c << cc2.c; // -1, -1
    cc1.c = 10;
    std::cout << cc1.c << cc2.c; // 10, -1
    // std::cout << cc1.a; // error, private
    std::cout << cc1.fa(); // -2
    // std::cout << cc2.fc(); // error, private
    std::cout << cc2.ff(); // -3

    return 0;
}