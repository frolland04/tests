#include <cstdio>
#include <iostream>
#include <optional>
#include <string>
#include <tuple>
#include <type_traits>
#include <functional>


class C {
public:
    auto get_a() const { return a; }
    void set_a(int _a = def_a) { a = _a; }
    friend class B;
private:
    static int a; // see outside
    static const int def_a{0};
};

constinit int C::a{def_a};
// static non-const initialization
// (must be outside class-scope)

class B {
public:
    static void reset() { C::a = C::def_a; }
};


int main ()
{ 
    C cc;
    // std::cout << C::a; // error, private
    std::cout << cc.get_a();

    cc.set_a(10);
    std::cout << cc.get_a();
    
    cc.set_a(20);
    std::cout << cc.get_a();

    cc.set_a();
    std::cout << cc.get_a();
    
    B::reset();
    std::cout << cc.get_a();
    return 0;
}