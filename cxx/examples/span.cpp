#include <iostream>
#include <span>
#include <vector>

int main()
{    
    // Create a vector of integers
    std::vector<int> nbs = {1, 2, 3, 4, 5, 6};
    for (const auto & elt : nbs) {
        std::cout << elt << " ";
    }
    std::cout << '\n';

    // Create a span to reference a portion
    // of the vector, covers [2, 3, 4]
    std::span<int> span(nbs.data() + 1, 3);

    // Access and modify elements through the span
    for (auto & elt : span) {
        elt *= 10;
    }

    // Print the modified elements using the original vector
    for (const auto & elt : nbs) {
        std::cout << elt << " ";
    }
    std::cout << '\n';

    // 1 2 3 4 5 6 
    // 1 20 30 40 5 6 

    return 0;
}
