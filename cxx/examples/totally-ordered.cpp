#include <concepts>
#include <iostream>
#include <string>

template <std::totally_ordered T>
void compare(const T& a, const T& b) {
    if (a == b) {
        std::cout << "a = b";
    } else if (a < b) {
        std::cout << "a < b";
    } else {
        std::cout << "a > b";
    }
}

int main()
{
    int a(3), b(5);
    compare(a, b); // "a < b"

    static_assert(std::totally_ordered<int>);
    static_assert(std::totally_ordered<double>);
    static_assert(std::totally_ordered<std::string>);

    return 0;
}
