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

template<typename T>
concept OutputStreamCapable = requires(T a, std::ostream &os)
{
    { os << a } -> std::convertible_to<std::ostream&>;
};

template <typename T>
requires OutputStreamCapable<T> && std::copy_constructible<T>
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

class D { };
class E {
    E(const E&) = delete;
    friend std::ostream& operator<<(std::ostream&, const E&);
};

int main()
{
    C<std::string> c1{"c1"};
    C c2{22};

    D dd;
    // std::cout << dd; // error, not match 'operator<<()'

    // C<D> c3; // error "constraints not satisfied"
    // substitution of 'template<class T>  requires
    // OutputStreamCapable<T> struct C [with T = D]':
    // note: the required expression '(os << a)' is invalid

    // C<E> c4; // error "constraints not satisfied"

    return 0;
}
