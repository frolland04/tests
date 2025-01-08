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
    auto print = [](const auto & v) {
        for (const auto & elt : v)
            std::cout << elt << ' ';
        std::cout << '\n';
    };
 
    std::array p {1, 6, 1, 6, 1, 6};
    print(p); // 1 6 1 6 1 6 

    std::ranges::replace(p, 6, 9);
    print(p); // 1 9 1 9 1 9 

 
    std::array q {1, 2, 3, 6, 7, 8, 4, 5};
    print(q); // 1 2 3 6 7 8 4 5 

    std::ranges::replace_if(q, [](int x) { return 5 < x; }, 5);
    print(q); // 1 2 3 5 5 5 4 5 

    return 0;
}