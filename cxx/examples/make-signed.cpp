#include <concepts>
#include <iostream>
#include <type_traits>

using T = int;
using U = unsigned int;
using V = std::make_signed_t<U>;

int main()
{
    static_assert(std::is_signed<T>()); // OK
    // static_assert(std::is_signed<U>()); // error.

    static_assert(std::is_signed<V>()); // OK

    return 0;
}





