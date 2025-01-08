#include <iostream>
#include <list>

int main()
{
    std::list<int> lst;

    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(1);
    lst.push_back(2);

    for (const auto & value : lst) {
        std::cout << value << " ";
    }
    std::cout << '\n';

    // 10 20 1 2

    for (auto it = lst.cbegin(); it != lst.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << '\n';

    // 10 20 1 2

    return 0;
}
