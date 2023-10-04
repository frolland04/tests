#include <iostream>
#include <vector>
#include <functional> // for std::reference_wrapper

int main()
{
    int a = 1, b = 2, c = 3;

    std::vector<std::reference_wrapper<int>> v;

    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    
    for (auto & i : v) {
        std::cout << i << " "; // 1 2 3
    }

    v[0].get() = 10;
    v[1].get() = 20;
    v[2].get() = 30;
    
    for (auto & i : v) {
        std::cout << i << " "; // 10 20 30
    }

    return 0;
}
