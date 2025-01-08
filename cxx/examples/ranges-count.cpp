#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
#include <ranges>

int main()
{
    std::vector<int> v{1, 2, 3, 4, 4, 3, 7, 8, 9, 10}; 
 
    std::cout << std::ranges::count(v.begin(), v.end(), 3) << '\n';
    // 2
    std::cout << std::ranges::count(v, 5) << '\n';
    // 0
 
    int n = std::ranges::count_if(v.begin(), v.end(),
      [](int i){ return i % 3 == 0; });
    std::cout << n << '\n';
    // 3
 
    int m = std::ranges::count_if(v,
      [](int i){ return i % 11 == 0; });
    std::cout << m << '\n';
    // 0

    return 0;
}