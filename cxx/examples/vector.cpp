#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v;
    v.reserve(10);

    const auto j{999};
    v.push_back(j);

    std::cout << v.capacity() << std::endl;
    std::cout << v.size() << std::endl;

    auto is = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (const auto& i : is) {
        v.push_back(i);
    }

    std::cout << v.capacity() << std::endl;
    std::cout << v.size() << std::endl;

    // 10
    // 1
    // 20
    // 11

    std::cout << v[0] << std::endl;
    std::cout << v[10] << std::endl;
    std::cout << v[11] << std::endl;     // may or may not do bounds-checking
    std::cout << v.at(11) << std::endl;  // std::out_of_range

    // 999
    // 10
    // 0
    // <!>

    return 0;
}
