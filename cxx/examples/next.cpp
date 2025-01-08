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
    auto s{2};
    for (auto it = lst.cbegin(); it != lst.cend();) {
        std::cout << *it << ",";
        std::cout << std::distance(it, lst.cend()) << " ";
        
        if (std::distance(it, lst.cend()) < s)
            it = lst.cend(); // increment past end is UB :-|
        else
            it = std::next(it, s); // see also std::advance()
    }
    std::cout << '\n';

    // 1,9 3,7 5,5 7,3 9,1

    return 0;
}
