#include <algorithm>
#include <cassert>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <utility>
#include <vector>
#include <random>

auto dice() {
    static std::uniform_int_distribution<int> dist {1, 10};
    static std::random_device rd_device;
    static std::mt19937 rd_engine {rd_device()};
    return dist(rd_engine);
}
 
int main()
{
    std::array<int, 8> v;
 
    std::ranges::generate(v.begin(), v.end(), dice);

    for (const auto i : v)
        std::cout << i << ' ';
    std::cout << '\n'; // 10 6 1 3 7 1 10 10 

    std::ranges::generate(v, dice);

    for (const auto i : v)
        std::cout << i << ' '; // 8 8 10 4 7 10 2 4
    std::cout << '\n';
 
    int n{0};
    std::ranges::generate(v, [&n]() { return n++; });

    for (const auto i : v)
        std::cout << i << ' ';
    std::cout << '\n'; // 0 1 2 3 4 5 6 7

    return 0;
}