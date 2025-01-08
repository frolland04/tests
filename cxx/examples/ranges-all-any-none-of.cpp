#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <utility>
#include <vector>
#include <functional>

int main()
{
    namespace rg = std::ranges;
    std::vector<int> v({2,4,6,8,10,12,14});

    rg::copy(v, std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    auto DivisibleBy = [](int d) {
        return [d](int m) { return m % d == 0; };
    };
 
    if (rg::all_of(v, DivisibleBy(2)))
        std::cout << "All numbers are even\n";
 
    if (rg::none_of(v, DivisibleBy(17)))
        std::cout << "None of them is divisible by 17\n";   

    if (rg::any_of(v, DivisibleBy(7)))
        std::cout << "At least one number is divisible by 7\n";

    // 2 4 6 8 10 12 14 
    // All numbers are even
    // None of them is divisible by 17
    // At least one number is divisible by 7

    return 0;
}