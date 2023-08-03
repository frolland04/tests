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

template <typename... Ts>
struct Tuple {};

template <int... Ts>
struct Tuple2 {};

template <class... Ts>
void f(Ts... args) {};

int main() {
    Tuple<> t0;            // OK: no arg
    Tuple<int> t1;         // OK: int
    Tuple<int, float> t2;  // OK: int, float
    //Tuple<0> t3;         // error, not a type
    Tuple2<0> t4;          // OK, non type value

    f();        // OK: no arg
    f<>();      // OK: equivalent

    f(1);       // OK: int (deduced)
    f<>(1);     // OK: equivalent
    f<int>(1);  // OK: equivalent

    f(2, 1.0);  // OK: int, double (deduced)

    return 0;
}