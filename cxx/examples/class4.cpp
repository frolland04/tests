#include <cstdio>
#include <iostream>
#include <optional>
#include <string>
#include <tuple>
#include <type_traits>
#include <functional>


class C {
public:
    auto get_a() { return a;}
    void set_a(int _a) { a = _a; }
    void set_a(const std::string & s) { a = std::stoi(s); }

    void set_a() const ; // outside
    auto aaa() const { semaphore = true; return a; }

private:
    int a{-1};
    mutable bool semaphore{false};
};

// was not defined at class-scope
// void C::set_a() const { a = 10; } // error, RO


int main ()
{ 
    C cc;
    std::cout << cc.get_a();
    cc.set_a(10);
    std::cout << cc.get_a();
    cc.set_a("500");
    std::cout << cc.get_a();

    return 0;
}