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
    static constexpr int def_a{0};
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
    std::ostream & os{std::cout};
    C cc;
    // os << C::a; // error, private
    os << cc.get_a() << '\n'; // 0

    cc.set_a(10);
    os << cc.get_a() << '\n'; // 10
    
    cc.set_a(20);
    os << cc.get_a() << '\n'; // 20

    cc.set_a();
    os << cc.get_a() << '\n'; // 0
    
    B::reset();
    os << cc.get_a() << '\n'; // 0
    
    return 0;
}