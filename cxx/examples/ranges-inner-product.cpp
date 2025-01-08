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
    namespace rg = std::ranges;

    std::vector<int> a{0, 1, 2, 3, 4};
    std::vector<int> b{5, 4, 2, 3, 1};
 
    int ip = std::inner_product(a.begin(), a.end(),
                                b.begin(),
                                0);
    std::cout << "Inner product of a and b: " << ip << '\n';
    // 21
 
    int pm = std::inner_product(a.begin(), a.end(),
                                b.begin(),
                                0,
                                std::plus<>(),
                                std::equal_to<>());
    std::cout << "Number of pairwise matches between a and b: " << pm << '\n';
    // 2

    return 0;
}