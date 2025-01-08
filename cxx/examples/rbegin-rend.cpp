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

    for (auto it = lst.rbegin(); it != lst.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << '\n';

    // 2 1 20 10

    return 0;
}
