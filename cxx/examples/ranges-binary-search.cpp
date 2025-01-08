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
    std::vector<int> v({8,14,6,2,10,12,4});

    rg::sort(v);
    assert(rg::is_sorted(v));
 
    for (const int n : {2,3,4})
    {
        std::cout << n << ": ";
        rg::binary_search(v, n)
            ? std::cout << "found" << '\n'
            : std::cout << "not found" << '\n';
    }

    // 2: found
    // 3: not found
    // 4: found

    return 0;
}