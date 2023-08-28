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

void f(std::weak_ptr<C>& C){};
void g(std::shared_ptr<C>& C){};

auto & os{std::cout};

int main() {
    os << "(1)" << std::endl;

    std::weak_ptr<C> wp1;
    std::weak_ptr<C> wp2{wp1};
    std::weak_ptr<C> wp3;
    wp3 = wp1;

    os << "(2)" << std::endl;

    std::shared_ptr<C> sp;
    sp.reset(new C{50});
    os << sp->a << std::endl;
    os << (*sp).a << std::endl;
    sp->fc();
    (*sp).fc();

    os << "(3)" << std::endl;

    std::weak_ptr<C> wp{sp};
    os << (wp.expired() ? "expired" : "valid") << std::endl;

    os << "(4)" << std::endl;

    sp.reset();
    os << (wp.expired() ? "expired" : "valid") << std::endl;

    os << "(5)" << std::endl;

    // (1)
    // (2)
    // 50
    // 50
    // (3)
    // valid
    // (4)
    // del50
    // expired
    // (5)
}
