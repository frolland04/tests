#include <iostream>
#include <vector>
#include <memory_resource>

int main()
{
    // Create synchronized_pool_resource
    std::pmr::synchronized_pool_resource pool;

    // Create vector using the pool resource
    std::pmr::vector<int> numbers({1, 2, 3, 4, 5}, &pool);

    // Print numbers
    for (int n : numbers) {
        std::cout << n << ' ';
    }

    return 0;
}
