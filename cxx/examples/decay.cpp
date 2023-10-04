#include <type_traits>

int main()
{
    using T = std::decay_t<const int&>;  // Removes const and reference, becomes int
    T a;
    static_assert(std::is_same<int, T>::value);

    return 0;
}