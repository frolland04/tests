#include <iostream>
#include <vector>
#include <string>
#include <memory_resource>

int main()
{
    // Create a buffer on the stack
    char buffer[1024];

    // Create a monotonic_buffer_resource using the buffer
    std::pmr::monotonic_buffer_resource resource(buffer, sizeof(buffer));

    // Create a vector that uses the buffer for its allocator
    std::pmr::vector<std::pmr::string> sv(&resource);

    // Add some strings to the vector
    sv.push_back("Hello");
    sv.push_back("world!");

    for (const auto & s : sv) {
        std::cout << s << ' ';
    }

    return 0;
}
