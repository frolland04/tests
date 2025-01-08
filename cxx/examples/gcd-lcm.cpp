#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <utility>
#include <vector>

using namespace std::string_view_literals;

int main()
{
    constexpr int p{2 * 2 * 3}; // 12
    
    constexpr int q{2 * 3 * 3}; // 18

    std::cout << std::gcd(p, q) << '\n'; // 6

    std::cout << std::lcm(p, q) << '\n'; // 36

    return 0;
}