#include <iostream>
#include <format> // Hypothetical header for std::format

int main()
{
    std::string name = "Bob";
    int age = 30;
    double salary = 50000.0;

    std::string s = std::format("Hello, {}! "
                                "You are {} years old, "
                                "and your salary is {:.2f}.", name, age, salary);
    std::cout << s << std::endl;

    return 0;
}
