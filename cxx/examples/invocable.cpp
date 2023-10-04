#include <concepts>
#include <type_traits>
#include <iostream>
#include <functional>

void f(int) {}

template <std::invocable<int> F>
void call42(F&& func) {
    func(42);
}

int main()
{
    call42(f);

    static_assert(std::is_invocable_v<decltype(f), int>); // OK
    // static_assert(std::is_invocable_v<decltype(f), std::string>); // error.

    static_assert(std::invocable<decltype(f), int>); // OK

    return 0;
}
