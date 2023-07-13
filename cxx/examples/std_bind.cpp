#include <cstdio>
#include <iostream>
#include <optional>
#include <string>
#include <tuple>
#include <type_traits>
#include <functional>

double ratio (double x, double y) {
    return x/y;
}

struct S {
    double a,b;

    double mult() {
        return a*b; 
    }
};

int main ()
 {
  using namespace std::placeholders;    // _1, _2, _3

  auto five = std::bind(ratio,10,2); // 10/2
  std::cout << five() << '\n'; // 5

  auto half = std::bind(ratio,_1,2); // p1/2
  std::cout << half(10) << '\n'; // 5

  auto perm = std::bind(ratio,_2,_1); // p2/p1
  std::cout << perm(10,2) << '\n'; // 0.2

  auto round = std::bind<int>(ratio,_1,_2); // int(p1/p2)
  std::cout << round(10,3) << '\n'; // 3

  S foo {10,2};

  auto mult = std::bind(&S::mult,_1); // p1::mult
  std::cout << mult(foo) << '\n'; // 20

  auto a = std::bind(&S::a,foo); // foo.a
  std::cout << a() << '\n'; // 10
  
    return 0;
}