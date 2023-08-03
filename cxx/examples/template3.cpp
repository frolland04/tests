#include <cmath>
#include <cstdio>
#include <fstream>
#include <functional>
#include <iostream>
#include <optional>
#include <string>
#include <tuple>
#include <type_traits>

template <typename T>
struct C
{
    C(const T& _id) : id{_id} {
        std::cout << "ctor " << id << std::endl;
    }

    ~C() {
        std::cout << "dtor " << id << std::endl;
    }

    T id{};
};

int main()
{
    std::cout << "-1-" << std::endl;
    C<std::string> c1{"c1"}, c2{"c2"};

    std::cout << "-2-" << std::endl;
    // C<int> c3{"c1"}, c4{"c2"}; // error, invalid conversion
    C<int> c3{3}, c4{4};
    c4.id = 4;

    C c5{3}, c6{4};
    static_assert(std::is_same_v<decltype(c5), C<int>>);

    C c7{3.5}, c8{4.5};
    static_assert(std::is_same_v<decltype(c7), C<double>>);

    C<const double> pi{3.14};
    // pi.id = 6.28; // error, RO

    std::cout << "-3-" << std::endl;

    return 0;
}
