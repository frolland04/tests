#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include <tuple>
#include <type_traits>

class Canary {
public:
    Canary() {
        std::cout << "Canary" << std::endl;
    }

    ~Canary() {
        std::cout << "~Canary" << std::endl;
    }      
};

int main()
{
    Canary c;
}
