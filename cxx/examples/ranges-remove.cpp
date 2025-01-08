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

    std::vector<int> nbs = {1, 2, 3, 4, 3, 5, 6, 3, 7, 8};
    for (const auto & n : nbs) {
        std::cout << n << " ";
    } // 1 2 3 4 3 5 6 3 7 8 
    std::cout << std::endl;

    auto rm = rg::remove(nbs, 3);
    nbs.erase(rm.begin(), rm.end()); // unneeded items

    for (const auto & n : nbs) {
        std::cout << n << " ";
    } // 1 2 4 5 6 7 8 
    std::cout << std::endl;

    nbs = {1, 2, 3, 4, 3, 5, 6, 3, 7, 8};

    rm = rg::remove_if(nbs, [](int n) { return n % 2 != 0; });
    nbs.erase(rm.begin(), rm.end()); // unneeded items

    for (const auto & n : nbs) {
        std::cout << n << " ";
    } // 2 4 6 8 
    std::cout << std::endl;

    return 0;
}