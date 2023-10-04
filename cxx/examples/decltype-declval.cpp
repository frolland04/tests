#include <string>
#include <iostream>
#include <type_traits>
#include <utility>

template <typename T>
auto foo(const T& x)
 -> decltype(std::declval<T>().size())
{
    return x.size();
}

int main()
{
    int result = foo(std::string("hello")); // 5
    std::cout << result;

    return 0;
}