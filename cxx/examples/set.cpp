#include <iostream>
#include <set>

int main()
{
    std::set<int> s;

    s.insert(3);
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(0);

    for (const auto & elt : s) {
        std::cout << elt << " ";
    }

    // 0 1 2 3 

    return 0;
}
