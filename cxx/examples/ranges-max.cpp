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
    static_assert(rg::max({0x10, 0x20, 0x05, 0x01}) == 0x20);
  
    std::cout << rg::max(1, 9999) << '\n';
    std::cout << rg::max('a', 'b') << '\n';
    std::cout << rg::max({"a", "aa", "aaa"}) << '\n';
    std::cout << rg::max({"a", "aa", "aaa", "b"}) << '\n';
    std::cout << rg::max({"awesome", "beer", "crash"}) << '\n';
    std::cout << rg::max({"awesome"sv, "beer"sv, "crash"sv}, {}, &std::string_view::size) << '\n';

    // 9999
    // b
    // aaa
    // b
    // crash
    // awesome

    return 0;
}