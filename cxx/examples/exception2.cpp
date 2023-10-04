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

auto& os{std::cout};

int main()
{
    os << "Hello" << std::endl;

    try {
        std::string s;
        s.resize(std::numeric_limits<long>::max());

        // Uncatched exception:
        // terminate called after throwing an instance of 'std::bad_alloc'
        // what():  std::bad_alloc
        // Program terminated with signal: SIGSEGV
    } catch (std::exception& e) {
        os << "std::exception occurred " << e.what() << '\n';
    } catch (int e) {
        os << "int exception occurred " << e << '\n';
    } catch (std::bad_alloc& ba) {
        os << "std::bad_alloc occurred " << ba.what() << '\n';
    }
    // Warning: exception of type 'std::bad_alloc' will be
    // caught by earlier handler
    // -> should be placed BEFORE std::exception base class handler
    catch (...) {
        os << "Some exception has occurred " << '\n';
    }

    os << "World" << std::endl;

    return 0;
}
