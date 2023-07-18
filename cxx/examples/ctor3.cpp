#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <optional>
#include <string>
#include <tuple>
#include <type_traits>

class MyDouble {
public:
    MyDouble(double _d) : d{_d}
    {
        std::cout << "{" << d << "}" << std::endl;
    } // (2)

    MyDouble() : MyDouble{0.0}
    {
        std::cout << "{.}" << std::endl;
    } // (2)

    void set(double _d) { d = _d; }

    operator double() {
        std::cout << "d";
        return d;
    }

    MyDouble& operator=(double _d) {
        std::cout << "=";
        d = _d;
        return *this;  // rvalue
    }    

    MyDouble& operator=(const MyDouble& rhs) {
        std::cout << ":=";
        d = rhs.d;
        return *this;
    } // (1)

    MyDouble(const MyDouble& rhs) : d{rhs.d} {
        std::cout << "(" << d << ")" << std::endl;
    } // (3)
    
    
private:
    double d{0.0};
};

int main() {
    MyDouble d1, d2{}; // default ctor (2)
                       // {0}{.}, {0}{.}
    d1.set(8.375);
    std::cout << d1 << std::endl;  // d8.375
    d1 = 9.81;
    std::cout << d1 << std::endl;  // =d9.81

    d2 = d1;         // assign. (1)
                     // :=
    MyDouble d3{d2}; // copy    (3)
                     // (9.81)

    MyDouble d4{5.5};              // ctor (2)
                                   // {5.5}
    std::cout << d4 << std::endl;  // d5.5
}
