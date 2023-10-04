#include <variant>
#include <iostream>

int main()
{
    std::variant<int, double> var = 10;
    
    if (std::holds_alternative<int>(var)) {
        std::cout << "It's an int: " << std::get<int>(var) << std::endl;
    }
    if (std::holds_alternative<double>(var)) {
        std::cout << "It's a double: " << std::get<double>(var) << std::endl;
    }

    var = 3.14;
    std::cout << "Now it's a double: " << std::get<double>(var) << std::endl;
    // std::cout << "Now it's a int: " << std::get<int>(var) << std::endl; // std::bad_variant_access

    return 0;
}