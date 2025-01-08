#include <iostream>
#include <string>

int main()
{
    std::string fullName = "John-Doe";
    
    size_t pos = fullName.find("Doe");
    if (pos != std::string::npos) {
        fullName.replace(pos, 3, "Big");
    }

    pos = fullName.find('-');

    std::string firstName = fullName.substr(0, pos);
    std::string lastName  = fullName.substr(pos + 1);

    std::cout << fullName  << std::endl;
    std::cout << firstName << std::endl;
    std::cout << lastName  << std::endl;
    std::cout << fullName.size() << std::endl;

    // John-Big
    // John
    // Big
    // 8

    return 0;
}
