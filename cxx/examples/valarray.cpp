#include <algorithm>
#include <cassert>
#include <complex>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <random>
#include <ranges>
#include <utility>
#include <vector>
#include <valarray>


int main()
{
    std::valarray<int> v1 = {1, 2, 3, 4, 5 };
    std::valarray<int> v2 = {2, 4, 6, 8, 10};

    std::valarray<int> v = v1 + v2;
    v *= 2;
    v /= std::numbers::pi;

    for (const auto & i : v) {
        std::cout << i << " ";
    } // 2 4 6 8 10
    std::cout << '\n';

    return 0;
}