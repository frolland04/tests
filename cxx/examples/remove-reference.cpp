#include <type_traits>

int main()
{
    using T = std::remove_reference_t<int&>;

    static_assert(std::is_same<int, T>::value); // OK
    // static_assert(std::is_reference<T>::value); // error.

    return 0;
}