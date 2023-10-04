#include <concepts>
#include <iostream>
#include <type_traits>

using Ta  = int[];
using Tac = const Ta;
using Ip  = int*;

class A {};
class C {};
class D : public C {};

int main()
{
    static_assert(std::is_array<Ta>());
    static_assert(std::is_base_of<C, D>());
    // static_assert(std::is_base_of<A, D>()); // error.
    static_assert(std::is_class<A>());
    static_assert(std::is_const<Tac>());
    // static_assert(std::is_pointer<Ta>()); // error.
    static_assert(std::is_pointer<Ip>());

    return 0;
}





