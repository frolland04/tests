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
    double get() const { return d; }
    void set(double _d) { d = _d; }

    operator double() {
        std::cout << "d";
        return d;
    }  // could be marked as "explicit"

    explicit operator std::string() {
        std::cout << "s";
        return std::to_string(d);
    }

    MyDouble& operator=(double _d) {
        std::cout << "=";
        d = _d;
        return *this;  // rvalue
    }

    double operator/(int i) {
        std::cout << "/";
        return std::floor(d / i);
    }

    double operator%(int i) {
        std::cout << "%";
        return d - operator/(i) * i;
    }
    /*
    friend std::ostream& operator<<(std::ostream& os, const MyDouble& rhs) {
        std::cout << "<<" << rhs.d;
        return os;
    }
    */
    MyDouble& operator=(const MyDouble& rhs) = default;
    /*
    MyDouble& operator=(const MyDouble& rhs) {
        std::cout << ":=";
        d = rhs.d;
        return *this;
    }

    explicit MyDouble(double _d = 0.0) : d{_d} {
        std::cout << "{}";
    }
    */

   private:
    double d{0.0};
};

int main()
{
    MyDouble d1, d2;
    d1.set(8.375);
    std::cout << d1.get() << std::endl;  // 8.375
    d2.set(5.525);
    std::cout << d2.get() << std::endl;  // 5.525

    // d1 % 2;    // error, no match, operand "MyDouble" and "int"
    // d2 = 11.5; // error, no match
    // d2 += 2.0; // error, no match
    // d2 < 2.0;  // error, no match
    // d1 < d2;   // error, no match, operand "MyDouble" and "MyDouble"
    // d1 != d2;  // error, no match

    d2 = d1;
    MyDouble d3{d2};
    std::cout << d1.get() << d2.get() << d3.get() << std::endl;
    // 8.375

    std::cout << d1 << std::endl;                            // d8.375
    std::cout << static_cast<std::string>(d1) << std::endl;  // s8.375000
    std::cout << (std::string)d1 << std::endl;               // s8.375000
    std::cout << d1 << std::endl;                            // s8.375000
    double dd{d1};                                           // d
    std::cout << ":" << dd << std::endl;                     // :8.375

    d2 = 5.25;
    // d1 = d2 = 0.0;
    std::cout << d2 << std::endl;      // =d5.25
    std::cout << d2 / 2 << std::endl;  // /2
    std::cout << d2 % 2 << std::endl;  // %1.25

    return 0;
}
