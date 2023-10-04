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

    MyDouble& operator=(const MyDouble& rhs) = default; // (1)
    MyDouble() = default;                     // (2)
    MyDouble(const MyDouble& rhs) = default;  // (3)
    
private:
    double d{0.0};
};

int main()
{
    MyDouble d1, d2{}; // default ctor (2)
    d1.set(8.375);
    std::cout << d1 << std::endl;  // d8.375
    d1 = 9.81;
    std::cout << d1 << std::endl;  // =d9.81

    d2 = d1;         // default assign. (1)
    MyDouble d3{d2}; // default copy    (3)

    return 0;
}
