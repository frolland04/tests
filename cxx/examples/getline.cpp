#include <iostream>
#include <sstream>
#include <string>
 
int main()
{
    std::string name;

    std::getline(std::cin, name);
    std::cout << name << '\n';

    // Enter: "lorem ipsum doloret"
    // Displays: "lorem ipsum doloret"

    std::cin >> name;
    std::cout << name << '\n';

    // Enter: "lorem ipsum doloret"
    // Displays: "lorem"

    std::getline(std::cin, name);
    std::cout << name << '\n';

    // Displays: " ipsum doloret"

    std::istringstream is;
    is.str("1\n2\n3\n4\n5\n6\n7\n");
    for (std::string line; std::getline(is, line);)
        std::cout << line << ",";
 
    // 1,2,3,4,5,6,7,

    std::cout << std::endl;

    is.clear();
    is.str("a;b;c;d");
    for (std::string line; std::getline(is, line, ';');)
        std::cout << line << ',';

    // a,b,c,d,

    std::cout << std::endl;
}