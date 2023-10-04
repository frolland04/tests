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
#include <memory>


class C {
public:
    C(int p) : a{p} {}; // (1)
    C() noexcept = default; // (2) 
    ~C() { std::cout << "del" << a << std::endl; };
    C(const C&) noexcept = default; // (3)
    C& operator=(const C&) noexcept = default;
    C(C&&) noexcept = default; // (4)
    C& operator=(C&&) noexcept = default;

    int a{0};

    void fc() {};
};

void f(C&) {} ;
void g(C) {} ;
void h(C*) {} ;
void k(std::unique_ptr<C>& uc) {} ;
void l(std::unique_ptr<C>  uc) {} ;

int main()
{
    std::cout << "(1)" << std::endl;

    C c1;      // OK, uses (2)
    C c2{1};   // OK, uses (1)
    C c3{c2};  // OK, uses (3) or (4)

    std::cout << "(2)" << std::endl;

    std::unique_ptr<C> uc1{new C(1)};  // uses (1)
    auto uc2 = std::make_unique<C>();  // uses (2)
    auto uc3 = std::make_unique<C>(3); // uses (1)
    // type of uc2 and uc3 ? std::unique_ptr<C>

    std::cout << "(3)" << std::endl;
    
    std::unique_ptr<C> uc4;
    uc4 = std::make_unique<C>(4);
    uc4 = std::make_unique<C>(5);
    // uc4 = uc3; // error, impossible
    // C c4{uc4}; // error, no known conversion
    // auto uc5 = std::make_unique<C>(uc4); // error, idem
    // f(uc4);
    // g(uc4);
    auto uc5 = std::move(uc3);

    std::cout << "(4)" << std::endl;
    
    f(c2); // OK, "pass-by-reference"
    g(c2); // OK, copy using (3) or (4)

    std::cout << "(5)" << std::endl;
    
    f(*uc4.get());
    g(*uc4.get());
    h(uc4.get());
    k(uc4);
    // l(uc4); // error

    std::cout << "(6)" << std::endl;

    uc4->fc();

    // del1
    // del6
    // del6
    // del5
    // del0
    // del1
    // del1
    // del0

    return 0;
}
