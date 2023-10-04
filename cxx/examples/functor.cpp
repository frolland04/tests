#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <optional>
#include <string>
#include <tuple>
#include <type_traits>

class C {
public:
    void operator()() {
        return;
    }
};

class D {
public:
    void operator()() {
        std::cout << "D";
        return;
    }
};

constinit C NullImpl{};

void f(auto _impl)
{
    _impl();
    return;
}

int main()
{
    // f(); // error, need 1 argument
    f(NullImpl);

    D d;
    f(d);   // displays "D"
    f(D{}); // displays "D"
    // ^^ transient instance

    return 0;
}
