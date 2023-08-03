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

using S = std::string;
auto & os{std::cout};
template <typename T, typename U = T, int v = 0>
struct C {
    C(const T& _id) : id{_id}, x{} {
       os << "ctor " << id << std::endl;
    }

    ~C() {
       os << "dtor " << id << std::endl;
    }

    T id;
    U x;
};

// Must be outside class-scope
template <>
C<S, S, 0>::C(const S& _id) : id{ "'" + _id + "'" }, x{"!"} {
    os << "ctorSS0 id=" << id ;
    os << " x=" << "'" << x << "'" << " (v=0)" << std::endl;
}

template <>
C<S, S, 1>::C(const S& _id) : id{ "'" + _id + "'" }, x{"?"} {
    os << "ctorSS1 id=" << id ;
    os << " x=" << "'" << x << "'" << " (v=1)" << std::endl;
}

int main() {
    C<int, double, 1> c1{1}; // ctor 1
    C<int> c2{2};            // ctor 2
    C<S, S, 0> c3{"c3"};     // ctorSS0 id='c3' x='!' (v=0)
    C<S, S, 1> c4{"c4"};     // ctorSS1 id='c4' x='?' (v=1)

    return 0;
}