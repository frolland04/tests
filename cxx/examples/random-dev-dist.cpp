#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <random>
#include <ranges>
#include <utility>
#include <vector>
#include <functional>

using namespace std::string_view_literals;

int main()
{
    auto f = [](auto & g, auto & d) {
        std::map<int, int> h;

        for (auto n = 0; n != 10000; ++n)
          ++h[d(g)];

        for (auto [x, y] : h) std::cout << x << ':' << ceil(y / 100) << "%, ";
        std::cout << '\n';
    };

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> ud{0, 5};
    f(gen, ud);

    std::poisson_distribution<> pd(4);
    f(gen, pd);

    std::geometric_distribution<> gd;
    f(gen, gd);

    std::bernoulli_distribution bd(0.25);
    f(gen, bd);

    std::discrete_distribution<> dd({40, 10, 10, 80});
    f(gen, dd);

    // 0:15%, 1:16%, 2:16%, 3:16%, 4:16%, 5:16%, 
    // 0:1%, 1:7%, 2:14%, 3:19%, 4:19%, 5:15%, 6:10%, 7:6%, 8:3%, 9:1%, 10:0%, 11:0%, 12:0%, 16:0%, 
    // 0:49%, 1:24%, 2:12%, 3:6%, 4:3%, 5:1%, 6:0%, 7:0%, 8:0%, 9:0%, 10:0%, 11:0%, 12:0%, 13:0%, 
    // 0:74%, 1:25%, 
    // 0:28%, 1:6%, 2:6%, 3:57%, 

    return 0;
}