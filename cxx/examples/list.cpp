#include <iostream>
#include <list>

int main()
{
    std::list<int> lst;

    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    for (const auto & value : lst) {
        std::cout << value << " ";
    }
    std::cout << '\n';

    lst.remove(2);

    for (const auto & value : lst) {
        std::cout << value << " ";
    }
    std::cout << '\n';

    lst.insert(lst.begin(), 4);
    lst.insert(std::next(lst.begin(), 2), 5);

    for (const auto & value : lst) {
        std::cout << value << " ";
    }
    std::cout << '\n';

    // 1 2 3 
    // 1 3 
    // 4 1 5 3 

    return 0;
}
