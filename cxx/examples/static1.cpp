#include <iostream>
#include <string>

class C
{
public:
    C(const std::string & n = "?") : nn{n} { std::cout << "C:" << n << std::endl; }
    ~C() { std::cout << "~C:" << nn << std::endl; }
private:
    std::string nn;
};

class D
{
public:
    static C m;
};

C gc1{"gc1"};
static C gc2{"gc2"};
C D::m{"Dm"};

void f()
{
    std::cout << "->f!" << std::endl;
    C c{"c"};
    static C cc{"cc"};
    std::cout << "<-f!" << std::endl;
}

int main()
{
    std::cout << "->main!" << std::endl;
    f();
    std::cout << "<-main!" << std::endl;
    return 0;

    // C:gc1
    // C:gc2
    // C:Dm

    // ->main!
    // ->f!
    // C:c
    // C:cc
    // <-f!
    // ~C:c
    // <-main!

    // ~C:cc
    
    // ~C:Dm
    // ~C:gc2
    // ~C:gc1
}