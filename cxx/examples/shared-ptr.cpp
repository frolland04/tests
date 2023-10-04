#include <chrono>
#include <cmath>
#include <concepts>
#include <cstdio>
#include <exception>
#include <functional>
#include <iostream>
#include <limits>
#include <memory>
#include <optional>
#include <ostream>
#include <string>
#include <thread>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

class C {
   public:
    C(int p) : a{p} {};      // (1)
    C() noexcept = default;  // (2)
    ~C() { std::cout << "del" << a << std::endl; };
    C(const C&) noexcept = default;  // (3)
    C& operator=(const C&) noexcept = default;
    C(C&&) noexcept = default;  // (4)
    C& operator=(C&&) noexcept = default;

    int a{0};

    void fc(){};
};

void f(C&) {};
void g(C)  {};
void h(C*) {};
void k(std::shared_ptr<C>& C) {} ;
void l(std::shared_ptr<C>  C) {} ;

int main()
{
    std::cout << "(1)" << std::endl;

    C c1;      // OK, uses (2)
    C c2{1};   // OK, uses (1)
    C c3{c2};  // OK, uses (3) or (4)

    std::cout << "(2)" << std::endl;

    std::shared_ptr<C> sc1{new C(1)};   // uses (1)
    auto sc2 = std::make_shared<C>();   // uses (2)
    auto sc3 = std::make_shared<C>(3);  // uses (1)
    // type of sc2 and sc3 ? std::shared_ptr<C>

    std::cout << "(3)" << std::endl;

    std::shared_ptr<C> sc4;
    sc4 = std::make_shared<C>(4);
    sc4 = std::make_shared<C>(5); // frees 4
    sc4 = sc3;                    // frees 5
    // C c4{sc4}; // error
    // auto sc5 = std::make_shared<C>(sc4); // error
    // f(sc4); // error
    // g(sc4); // error
    auto sc5 = std::move(sc3);

    std::cout << "(4)" << std::endl;

    f(c2);  // OK, "pass-by-reference"
    g(c2);  // OK, copy using (3) or (4)

    std::cout << "(5)" << std::endl;

    f(*sc4.get());
    g(*sc4.get());
    h(sc4.get());

    std::cout << "(6)" << std::endl;
    
    k(sc4); // OK
    l(sc4); // OK

    sc4->fc();
    sc4.reset();

    std::cout << "(7)" << std::endl;

    // (1)
    // (2)
    // (3)
    // del4
    // del5
    // (4)
    // del1
    // (5)
    // del3
    // (6)
    // del3
    // del0
    // del1
    // del1
    // del1
    // del0

    return 0;
}
