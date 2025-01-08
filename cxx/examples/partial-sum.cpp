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
    std::vector<int> v(10, 2);

    for (const auto & n : v)
        std::cout << n << ' ';
    std::cout << '\n'; // 2 2 2 2 2 2 2 2 2 2 
 
    std::partial_sum(v.cbegin(), v.cend(), 
                     std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n'; // 2 4 6 8 10 12 14 16 18 20 
 
    std::partial_sum(v.cbegin(), v.cend(),
                     v.begin(),
                     std::multiplies<int>());
 
    for (const auto & n : v)
        std::cout << n << ' ';
    std::cout << '\n'; // 2 4 8 16 32 64 128 256 512 1024

    return 0;
}