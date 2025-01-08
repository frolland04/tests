#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <utility>
#include <vector>

int main()
{
    std::vector<int> v{2, 3, 4, 5, 2, 8, 15, 267};

    auto prt = [](const auto & n) { std::cout << n << ' '; };

    namespace rg = std::ranges;
    rg::for_each(std::as_const(v), prt);
    std::cout << "\n"; // 2 3 4 5 2 8 15 267

    rg::for_each(v, [](auto & n) { n = rg::clamp(n, 4, 8); });
    rg::for_each(std::as_const(v), prt);
    std::cout << "\n"; // 4 4 4 5 4 8 8 8
     
    return 0;
} 