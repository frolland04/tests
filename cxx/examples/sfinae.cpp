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

struct C {};
struct D {
  using I = C; // look at here
};

// (1)
template <class T>
void ff(T&) {
  std::cout << "f(T)" << std::endl;
}
// (2)
template <class T>
void ff(typename T::I &) {
  std::cout << "f(T::I)" << std::endl;
}
/*
// (3)
void ff(D::I &) {
  std::cout << "f(D::I)" << std::endl;
}
*/
int main()
{
    C cc;
    D dd;
    D::I di;

    ff(cc);    // OK, f(T)
    ff<C>(cc); // equivalent

    ff(dd);    // OK, f(T)
    ff<D>(dd); // equivalent
    
    ff(di);       // OK, f(T)
    ff<D::I>(di); // equivalent

    ff<C>(cc); // OK, f(T)
    ff<D>(cc); // OK, f(T::I)
}