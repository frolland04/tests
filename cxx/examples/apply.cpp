#include <iostream>
#include <tuple>
#include <utility>

void sum(int a, int b, int c)
{
    auto s = a + b;
    std::cout << "sum: " << s << ((s < c) ? "<" : ">=") << c << std::endl;
}

int main()
{
    std::tuple<int, int, int> values(3, 4, 8);
    std::apply(sum, values);
    // sum: 7<8

    values = {3, 4, 7};
    std::apply(sum, values);
    // sum: 7>=7

    return 0;
}
