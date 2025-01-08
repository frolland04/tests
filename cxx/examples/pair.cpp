#include <iostream>
#include <utility>

std::pair<int, int> divide(int n, int d)
{
    if (d == 0) {
        throw std::runtime_error("n cannot be 0");
    }
    return {n / d, n % d};
}

int main()
{
    int num = 17;
    int den = 4;

    auto result = divide(num, den);

    std::cout << "Q: " << result.first  << std::endl; // 4
    std::cout << "R: " << result.second << std::endl; // 1

    return 0;
}
