#include <cmath>
#include <cstdio>
#include <ostream>
#include <functional>
#include <iostream>
#include <optional>
#include <string>
#include <tuple>
#include <type_traits>
#include <concepts>

template <class T>
struct C
{
    C(const T&);
    ~C();

    T id;
};

template <class T>
C<T>::C(const T& _id) : id{_id} {
    std::cout << "ctor " << id << std::endl;
}

template <class T>
C<T>::~C() {
    std::cout << "dtor " << id << std::endl;
}

template class C<int>;
template class C<std::string>;

int main()
{
    C<int> c1{0};
    C<std::string> c2{std::string{"c2"}};

    return 0;
}
