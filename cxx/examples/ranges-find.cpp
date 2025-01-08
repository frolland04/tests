#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
#include <ranges>

int main()
{
    namespace rg = std::ranges;
    const auto v = {4, 1, 3, 2};
 
    std::cout << "3:" << (rg::find(v, 3) != v.end()) << '\n';
 
    std::cout << "5:" << (rg::find(v.begin(), v.end(), 5) != v.end()) << '\n';
 
    auto is_even = [](int x) { return x % 2 == 0; };
 
    if (auto result = rg::find_if(v.begin(), v.end(), is_even); result != v.end())
        std::cout << "even:" << *result << '\n';
 
    if (auto result = rg::find_if_not(v, is_even); result != v.end())
        std::cout << "odd:" << *result << '\n';
 
    auto div13 = [](int x) { return x % 13 == 0; };
 
    if (auto result = rg::find_if(v, div13); result == v.end())
        std::cout << "/13:none" << '\n';

    // 3:1
    // 5:0
    // even:4
    // odd:1
    // /13:none

    return 0;
}