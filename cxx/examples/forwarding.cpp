#include <cmath>
#include <concepts>
#include <cstdio>
#include <functional>
#include <iostream>
#include <optional>
#include <ostream>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>

class C {
};

void f(C &) {
  std::cout << "f(C&)" << std::endl;
}
void f(const C &) {
  std::cout << "f(const C&)" << std::endl;
}
void f(C &&) {
  std::cout << "f(C&&)" << std::endl;
}

// 'const' and '&&' not forwarded
template <typename T>
void ff(T x) {
  f(x);
}

// 'perfect' forwarding
template <typename T>
void ff2(T && x) { // "universal references"
  f(std::forward<T>(x));
}

int main()
{
    C cc;
    const auto & ro{cc};

    std::cout << "-1-" << std::endl;
    f(cc); // f(C&)
    f(ro); // f(const C&)
    f(std::move(cc)); // f(C&&)

    std::cout << "-2-" << std::endl;
    ff(cc); // f(C&)
    ff(ro); // f(C&)
    ff(std::move(cc)); // f(C&)

    std::cout << "-3-" << std::endl;
    ff2(cc); // f(C&)
    ff2(ro); // f(const C&)
    ff2(std::move(cc)); // f(C&&)

    std::cout << "-4-" << std::endl;

    return 0;
}
