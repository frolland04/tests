#include <any>
#include <iostream>

int main()
{
    std::any a = 42;

    if (a.type() == typeid(int)) {
        std::cout << "i:" << std::any_cast<int>(a) << std::endl;
    }

    a = std::string("hello");
    std::cout << "s:" << std::any_cast<std::string>(a) << std::endl;
    // std::cout << "i:" << std::any_cast<std::int>(a) << std::endl;
    // does NOT compile

    return 0;
}