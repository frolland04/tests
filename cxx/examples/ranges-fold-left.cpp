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
    std::vector<int> v {1, 2, 3, 4, 5, 6, 7, 8};
 
    auto sum = rg::fold_left(v.begin(), v.end(), 0, std::plus<>());
    std::cout << "sum: " << sum << '\n';
 
    auto mul = rg::fold_left(v, 1, std::multiplies<>());
    std::cout << "mul: " << mul << '\n';
 
    auto chs = rg::fold_left
    (
        v, "/", [](std::string s, int x) { return s + std::to_string(x) + '/' ; }
    );
    std::cout << "chs: " << chs << '\n';

    // sum: 36
    // mul: 40320
    // chs: /1/2/3/4/5/6/7/8/

    return 0;
}