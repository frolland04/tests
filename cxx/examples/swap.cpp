#include <algorithm>
#include <iostream>

int main()
{
    int a = 5, b = 10;
    std::swap(a, b);
    std::cout << "a: " << a << ", b: " << b << std::endl;  // Outputs: "a: 10, b: 5"

    return 0;
}
