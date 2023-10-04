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
    auto tp{std::chrono::system_clock::now()};
    auto tm{std::chrono::system_clock::to_time_t(tp)};
    os << ctime(&tm) << std::endl;
}

int main()
{
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

    return 0;
}
