#include <iostream>
#include <cassert>

int main() 
{
    constexpr int x = 5;

    // Compile-time check: if the condition is false, build fails.
    static_assert(x == 5, "x is not equal to 5!");
    
    // Once build is OK, at runtime.
    std::cout << "x = 5.\n";

    int y = 10;

    // Run-time check: if the condition is false, program terminates
    // (but not guaranteed with release builds)
    assert(y == 10);
    std::cout << "y is equal to 10.\n";

    return 0;
}
