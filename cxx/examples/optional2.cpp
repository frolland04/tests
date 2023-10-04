#include <optional>
#include <iostream>

std::optional<int> get_even(int x)
{
    return (x % 2 == 0) ?
        std::optional<int>{x} :
        std::nullopt;
}

int main()
{
    auto opt = get_even(2);
    if (opt.has_value())
    {
        std::cout << "Got an even number: "
                  << opt.value()
                  << std::endl;
    }

    return 0;
}