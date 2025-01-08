#include <iostream>
#include <string>

int main()
{
    std::string str = "Hello, world!";
    
    if (str.contains("world")) {
        std::cout << "world" << std::endl;
    }
    
    if (str.contains("earth")) {
        std::cout << "earth" << std::endl;
    }

    return 0;
}
