#include <iostream>
#include <memory>
 
struct C
{
    int a, b, c, d;

    C() {
        std::cout << "ctor, this = " << this << std::endl;
    }
 
    auto operator&() { return &d; }
};
 
template <typename T>
void f(T p)
{
    std::cout << "p = " << std::hex << reinterpret_cast<unsigned long long>(p) << '\n';
}
 
int main()
{
    C p; // ctor, this = 0x7ffc23ae03a0

    f(&p); // p = 7ffc23ae03ac

    f(std::addressof(p)); // p = 7ffc23ae03a0

    return 0;
}



