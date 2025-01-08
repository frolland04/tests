#include <iostream>
#include <array>

int main()
{
    // Declare and initialize a std::array of 5 integers
    std::array<int, 5> numbers{1, 2, 3, 4, 5};

    // Access elements
    std::cout << "Elements" << std::endl;
    for (auto & n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    // Get the size
    std::cout << "Size " << numbers.size() << std::endl;

    // Access a specific element by index
    int & elt{numbers[2]};
    std::cout << "Element [2] " << elt << std::endl;

    // Modify an element
    numbers[2] = 42;
    std::cout << "Element [2] " << elt << std::endl;

    return 0;
}
