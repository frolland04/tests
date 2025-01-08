#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <utility>
#include <vector>
#include <iomanip>

template<class T>
std::ostream & operator<<(std::ostream & os, std::initializer_list<T> const & list)
{
    for (  os << "{ "; auto const & elt : list)
           os << elt << ' ';
    return os << "} ";
}

int main()
{
    auto ignore_case = [](char a, char b) { return std::tolower(a) < std::tolower(b); };
 
    const auto
        a = {'a', 'b', 'c'},
        b = {'a', 'c'},
        c = {'a', 'a', 'b'},
        d = {'b', 'c', 'a'},
        e = {'g'},
        f = {'a', 'c', 'g'},
        g = {'A', 'B', 'C'},
        z = {'a', 'b', 'c', 'f', 'h', 'x'};
 
    std::cout
        << z << "\nincludes :" << std::boolalpha << '\n'
        << a << std::ranges::includes(z.begin(), z.end(), a.begin(), a.end()) << '\n'
        << b << std::ranges::includes(z, b) << '\n'
        << c << std::ranges::includes(z, c) << '\n'
        << d << std::ranges::includes(z, d) << '\n'
        << e << std::ranges::includes(z, e) << '\n'
        << f << std::ranges::includes(z, f) << '\n'
        << g << std::ranges::includes(z, g) << '\n'
        << g << std::ranges::includes(z, g, ignore_case) << '\n';

    // { a b c } true
    // { a c } true
    // { a a b } false
    // { b c a } false
    // { g } false
    // { a c g } false
    // { A B C } false
    // { A B C } true

    return 0;
}