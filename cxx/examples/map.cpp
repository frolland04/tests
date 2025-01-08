#include <iostream>
#include <map>

int main()
{
    std::map<std::string, int> m;

    m["Alice"]   = 30;
    m["Bob"]     = 25;
    m["Charlie"] = 35;
    m["Alicia"]  = 30;

    for (const auto & elt : m) {
        std::cout << elt.first << " is "
                  << elt.second << " years old." << std::endl;
    }

    // Alice is 30 years old.
    // Alicia is 30 years old.
    // Bob is 25 years old.
    // Charlie is 35 years old.

    return 0;
}
