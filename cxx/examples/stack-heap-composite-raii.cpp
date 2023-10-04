#include <chrono>
#include <cmath>
#include <concepts>
#include <cstdio>
#include <exception>
#include <functional>
#include <iostream>
#include <limits>
#include <optional>
#include <ostream>
#include <string>
#include <thread>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>


struct C {
    int a{10u};
    int b{0};
};

struct D {
    double d{20.5};
    C c;
};

struct E {
};


int main()
{
    // Stack
    // *****

    auto a{10u};
    if (a < 50u)
    {
        auto b{0};
        auto & ra{a};
        std::vector v{0,1,2};

        // ...
    }

    //auto & rb{b}; // error, not declared in this scope

    // Heap
    // ****

    if (a < 50u)
    {
        auto pi{new int{100u}};

        // ...

        delete pi;
        pi = nullptr;
    }

    // Composite
    // *********

    if (a < 50u)
    {
        C cc;
        D dd;

        // ...
    }

    // RAII
    // ****

    if (a < 50u)
    {
        std::vector v{0,1,2};

        // ...

        if (v.size() > 3) throw E{};

        // ...
    }

    return 0;
}
