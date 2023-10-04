#include <cstdio>
#include <iostream>
#include <optional>
#include <string>
#include <tuple>
#include <type_traits>
#include <functional>

class MyDouble
{
public:
    
private:
    double d;
};

int main ()
{ 
    int a{10}, b{20};
    std::cout << a + b; // 30
    a += 5;
    std::cout << a; // 15
    std::cout << a / 2 << a % 2; // 7, 1

    double c{15.0};
    std::cout << c / 2; // 7.5
    // std::cout << c % 2; // error, invalid operands to binary "operator%"

    return 0;
}