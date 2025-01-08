#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
#include <ranges>

int main()
{
    std::vector<int> s({0,1,2,3,4,5,6,7,8,9});
    std::vector<int> d(10, 0);

    for (const auto & value : d) {
      std::cout << value << " ";
    }
    std::cout << '\n';
    // 0 0 0 0 0 0 0 0 0 0
 
    std::ranges::copy(s.begin(), s.end(), d.begin());
  
    std::ranges::copy(d, std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
    // 0 1 2 3 4 5 6 7 8 9
  
    std::ranges::copy_if(d, std::ostream_iterator<int>(std::cout, " "),
                         [](int x) { return (x % 2) == 1; });
    std::cout << '\n';
    // 1 3 5 7 9

    return 0;
}