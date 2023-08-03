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


struct base {
  int i{0};
  void f() { i++; };
};
struct left : base { };
struct right : base { };
struct derived : left, right { };

struct left2 : virtual base { };
struct right2 : virtual base { };
struct derived2 : left2, right2 { };

// base   base
//  |      |
// left  right
//   \    /
//   derived

int main()
{
    derived d;
    //d.i = 3;           // error, ambiguous
    left & l = d;
    right & r = d;
    
    std::cout << l.i << r.i << std::endl;

    l.f();

    std::cout << l.i << r.i << std::endl;

    //assert(r.i == 1);    // error

    // *************************************************

    derived2 d2;
    d2.i = 3;           // OK
    left2 & l2 = d2;
    right2 & r2 = d2;
    
    std::cout << l2.i << r2.i << std::endl;

    l2.f();

    std::cout << l2.i << r2.i << std::endl;

    assert(r2.i == 4);  // OK

    return 0;
}