#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <utility>
#include <vector>

struct S {
    void operator()(int n) { sum += n; }
    int sum{0};
};

int main()
{
    std::vector<int> v{3, 4, 2, 8, 15, 267};

    auto prt = [](const auto & n) { std::cout << n << ' '; };

    namespace rg = std::ranges;
    rg::for_each(std::as_const(v), prt);
    std::cout << "\n";

    rg::for_each(v, [](int & n) { ++n; });

    auto [i, s] = rg::for_each(v.begin(), v.end(), S());
    assert(i == v.end());

    rg::for_each(v.cbegin(), v.cend(), prt);

    std::cout << "\n";
    std::cout << "S: " << s.sum << '\n';

    using pair_t = std::pair<int, std::string>;
    std::vector<pair_t> ps{{1, "a"}, {2, "b"}, {3, "c"}};

    rg::for_each(ps, prt, [](const pair_t & p) { return p.first; });
    std::cout << "\n";
    rg::for_each(ps, prt, &pair_t::second);
    std::cout << "\n";

    // 3 4 2 8 15 267 
    // 4 5 3 9 16 268 
    // S: 305
    // 1 2 3 
    // a b c 

    return 0;
}