#include <cstdio>
#include <iostream>
#include <optional>
#include <string>
#include <tuple>
#include <type_traits>
#include <functional>


class C {
public:
    auto get_a() const { return a;}
    friend void set_a(C & _c, int _a); // outside 
    friend void set_a(C & _c, const std::string & s); // outside 
    friend class B;
private:
    int a{-1};
};

void set_a(C & _c, int _a) {
     _c.a = _a;
}
void set_a(C & _c, const std::string & s) {
     _c.a = std::stoi(s);
}

class B {
public:
    void reset(C & _c) { _c.a = 0; }
};


int main ()
{ 
    C cc;
    std::cout << cc.get_a(); // -1
    set_a(cc, 10);
    std::cout << cc.get_a(); // 10
    set_a(cc, "500");
    std::cout << cc.get_a(); // 500

    B bb;
    bb.reset(cc);
    std::cout << cc.get_a(); // 0
    return 0;
}