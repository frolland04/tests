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

template <class T>
struct C {
    C(const T& _id) : id{_id} {
       os << "ctor " << id << std::endl;
    }

    ~C() {
       os << "dtor " << id << std::endl;
    }

    T id;
};

// Must be outside class-scope
template <>
C<S>::C(const S& _id) : id{ "'" + _id + "'" } {
    os << "ctor for string id " << id << std::endl;
}

int main()
{
    C<int> c1{0};
    C<S> c2{"c2"};

    return 0;
}
