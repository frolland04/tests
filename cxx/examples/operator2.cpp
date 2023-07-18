#include <cstdio>
#include <functional>
#include <iostream>
#include <optional>
#include <string>
#include <tuple>
#include <type_traits>
#include <cmath>

class MyDouble {
public:
    double get() const { return d; }
    void set(double _d) { d = _d; }

    operator double() {
        std::cout << "d";
        return d;
    } // could be marked as "explicit"

    explicit operator std::string() {
        std::cout << "s";
        return std::to_string(d);
    }

    MyDouble& operator=(double _d) {
        d = _d;
        return *this;
    }

    double operator%(int i) {
        return d - std::floor(d / i) * i;
    }

private:
    double d{0.0};
};

int main() {
    MyDouble d1;
    d1.set(8.375);
    std::cout << d1.get() << std::endl; // 8.375
    std::cout << d1 << std::endl; // d8.375
    std::cout << static_cast<std::string>(d1) << std::endl; // s8.375000
    double dd{d1}; // d
    std::cout << ":" << dd << std::endl; // :8.375

    MyDouble d2;
    d2 = 5.25;
    std::cout << d2 << std::endl;     // d5.25
    std::cout << d2 / 2 << std::endl; // d2.625
    std::cout << d2 % 2 << std::endl; // 1.25
}







