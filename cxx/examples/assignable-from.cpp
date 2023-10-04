#include <concepts>
#include <iostream>
#include <type_traits>

struct A {};
struct B {};
struct C : public A {
    C& operator=(const A&) { return *this; }
};
template <std::assignable_from<const A&> T>
class D {};

int main()
{
    // static_assert(std::is_assignable_v<B, A>); // error.
    static_assert(std::is_assignable_v<C, A>);  // OK
    static_assert(std::is_assignable_v<A, A>);  // OK
    // static_assert(std::is_assignable_v<A, C>); // error.
    static_assert(std::assignable_from<C&, const A&>);

    D<A&> da; // OK
    // D<B> db; // error
    D<C&> dc; // OK

    return 0;
}
