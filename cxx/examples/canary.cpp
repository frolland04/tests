#include <cmath>
#include <cstdio>
#include <fstream>
#include <functional>
#include <iostream>
#include <optional>
#include <string>
#include <tuple>
#include <type_traits>

class Canary {
public:
     Canary() { std::cout << "ctor" << std::endl; }
    ~Canary() { std::cout << "dtor" << std::endl; }
};

int main() 
{
    Canary c;

    return 0;
}
