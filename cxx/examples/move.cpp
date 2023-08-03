#include <iostream>
#include <string>
#include <utility>
 
class C
{
public:
    using S = std::string;
 
    C(const S& _name = "test") : s(_name) {
        std::cout << "ctor " << _name << "\n";
    }  

    C(C&& o) : s(std::move(o.s)) { // not const arg
        std::cout << "(&&)\n";
    }
 
    C& operator=(const C& _other)
    {
         s = _other.s;
         std::cout << "=(&)\n";
         return *this;
    }
 
    C& operator=(C&& _other) // not const arg
    {
         s = std::move(_other.s);
         std::cout << "=(&&)\n";
         return *this;
    }

    std::string& get_name() { return s; }

private:
    std::string s;

};
 
int main()
{
    C c1{"c1"}, c2{"c2"}, c3{"c3"};
    
    std::cout << "Before move, c1.s = \"" << c1.get_name() << "\"\n";
    c2 = std::move(c1);
    std::cout << "After move, c1.s = \"" << c1.get_name() << "\"\n";

    std::cout << "Before move, c3.s = \"" << c3.get_name() << "\"\n";
    C c4{std::move(c3)};
    std::cout << "After move, c3.s = \"" << c3.get_name() << "\"\n";
}