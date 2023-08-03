#include <cmath>
#include <concepts>
#include <cstdio>
#include <functional>
#include <iostream>
#include <optional>
#include <ostream>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>
#include <chrono>
#include <thread>

auto & os{std::cout};
void timestamp() {
   os << std::chrono::system_clock::now() << std::endl;
}

int main() {
    os << "Hello" << std::endl;
    timestamp();

    try {
        throw 20;
        std::this_thread::sleep_for (std::chrono::seconds(5));
    }
    catch (int e) {
        os << "An exception occurred " << e << '\n';
    }

    os << "World" << std::endl;
    timestamp();
}
