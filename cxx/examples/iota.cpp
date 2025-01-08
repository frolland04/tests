#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <utility>
#include <vector>
#include <list>

using namespace std::string_view_literals;

int main()
{
    std::vector<int> v(10);

    for (const auto & n : v)
        std::cout << n << ' ';
    std::cout << '\n'; // 0 0 0 0 0 0 0 0 0 0 

    std::iota(v.begin(), v.end(), -4);
    
    for (const auto & n : v)
        std::cout << n << ' ';
    std::cout << '\n'; // -4 -3 -2 -1 0 1 2 3 4 5 
    
    return 0;
}