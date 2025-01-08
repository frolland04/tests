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
 
int main()
{
    std::vector<int> v {0, 1, 2, 3, 4, 5};
 
    std::ranges::fill(v.begin(), v.end(), -1);

    for (const auto & value : v) {
        std::cout << value << " ";
    }
    std::cout << '\n'; // -1 -1 -1 -1 -1 -1 

    std::ranges::fill(v, 10);

    for (const auto & value : v) {
        std::cout << value << " ";
    }
    std::cout << '\n'; // 10 10 10 10 10 10 

    std::ranges::fill_n(v.begin(), 4, 5);

    for (const auto & value : v) {
        std::cout << value << " ";
    }
    std::cout << '\n'; // 5 5 5 5 10 10 

    return 0;
}