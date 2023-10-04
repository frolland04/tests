#include <concepts>
#include <type_traits>
#include <iostream>

// Function template using the std::signed_integral concept
template <std::signed_integral T>
class C {};

int main()
{
    static_assert(std::is_integral_v<int> &&
                  std::is_signed_v<int>); // OK
    // static_assert(std::is_integral_v<unsigned int> &&
    //               std::is_signed_v<unsigned int>); // error.
    static_assert(std::is_integral_v<long> &&
                  std::is_signed_v<long>); // OK                  
    static_assert(std::signed_integral<long>); // OK       

    C<int> c1; // OK
    // C<std::string> c2; // error.

    return 0;
}
