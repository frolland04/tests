#include <iostream>
#include <string>

int main()
{
    // Create a UTF-8 encoded string with some non-ASCII characters
    std::u8string greeting = u8"Hello, 世界!";  // "Hello, World!" in English and Chinese

    // Display the string
    std::cout << "Greeting: " << (const char*)greeting.c_str() << std::endl;

    // Find the position of a non-ASCII character
    size_t pos = greeting.find(u8"世");
    if (pos != std::u8string::npos) {
        std::cout << "Found '世' at position: " << pos << std::endl;
    }
    else
    {
        std::cout << "'世' not found!" << std::endl;
    }

    return 0;
}
