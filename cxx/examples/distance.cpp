#include <iostream>
#include <list>

int main()
{
    std::list<int> lst = {1,2,3,4,5,6,7,8,9};

    for (const auto & value : lst) {
        std::cout << value << " ";
    }
    std::cout << '\n';

    // 1 2 3 4 5 6 7 8 9 

    for (auto it = lst.cbegin(); it != lst.cend(); ++it) {
        std::cout << *it << ",";
        std::cout << std::distance(it, lst.cend()) << " ";
    }
    std::cout << '\n';

    // 1,9 2,8 3,7 4,6 5,5 6,4 7,3 8,2 9,1

    return 0;
}
