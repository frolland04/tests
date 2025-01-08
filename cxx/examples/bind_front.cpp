#include <iostream>
#include <functional>

void greet(const std::string& greeting, const std::string& name)
{
    std::cout << greeting << ", " << name << "!" << std::endl;
}

int main()
{
    auto say_hello = std::bind_front(greet, "Hello");
    say_hello("Alice");
    // Hello, Alice!

    say_hello("Bob");
    // Hello, Bob!

    return 0;
}
