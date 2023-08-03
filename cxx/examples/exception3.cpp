#include <chrono>
#include <cmath>
#include <concepts>
#include <cstdio>
#include <exception>
#include <functional>
#include <iostream>
#include <limits>
#include <optional>
#include <ostream>
#include <string>
#include <thread>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

using S = std::string;
auto& os{std::cout};
struct UserExc : std::exception {
    explicit UserExc(int _ec) : ec{_ec} {
        msg = "UserExc-";
        msg.append(std::to_string(ec));
    }
    const char* what() const noexcept override { return msg.c_str(); }
    int ec{-1};
    S msg{"?"};
};

void f() { os << "f()" << std::endl; }

void g() {
    os << "g()" << std::endl;
    throw UserExc{404};
}

int main() {
    os << "Hello" << std::endl;

    try {
        f();
        g();
    } catch (std::exception& e) {
        os << "std::exception: " << e.what() << '\n';
    } catch (...) {
        os << "Some exception has occurred." << '\n';
    }

    os << "World" << std::endl;
}
