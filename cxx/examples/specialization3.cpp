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
template <class T, class U>
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

template <class U>
struct C<S,U> {
    C(const S& _id) : id{_id} {
       os << "ctor T=S " << id << std::endl;
       // os << x; // error, undeclared here.
    }
    ~C() {
       os << "dtor T=S " << id << std::endl;
    }

    S id;
};

int main()
{
    C<int, double> c1{1}; // ctor 1
    C<int, int> c2{2};    // ctor 2 

    C<S, int> c3{"c3"};   // ctor T=S c3
    C<int, S> c4{4};      // ctor 4
    C<S, S> c5{"c5"};     // ctor T=S c5

    return 0;
}
