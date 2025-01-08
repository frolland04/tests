#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <utility>
#include <vector>
#include <iomanip>

int main()
{
    std::string s{"hello"};
    std::cout << std::quoted(s) << '\n';
    std::ranges::transform(s.cbegin(), s.cend(),
                           s.begin(), // <-- same location
                           [](unsigned char c) { return std::toupper(c); });
    std::cout << std::quoted(s) << '\n';

    std::vector<std::size_t> ascii;
    std::ranges::transform(s.cbegin(), s.cend(),
                           std::back_inserter(ascii), // <-- output
                           [](unsigned char c) { return c; });

    for (const auto & value : ascii) {
        std::cout << value << ' ';
    }
    std::cout << '\n';

    std::ranges::transform(ascii, ascii,
                           ascii.begin(),
                           std::plus<>{});

    for (const auto & value : ascii) {
        std::cout << value << ' ';
    }
    std::cout << '\n';

    // "hello"
    // "HELLO"
    // 72 69 76 76 79
    // 144 138 152 152 158

    return 0;
}