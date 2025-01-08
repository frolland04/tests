#include <algorithm>
#include <cassert>
#include <chrono>
#include <complex>
#include <ctime>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <random>
#include <ranges>
#include <thread>
#include <utility>
#include <valarray>
#include <vector>

int main()
{
    namespace co = std::chrono;
    using namespace std::chrono_literals;

    auto one_second = 1s;
    std::cout << co::seconds(1s).count() << "\n" // 1
              << co::seconds(1s)         << "\n" // 1s
              << co::milliseconds(1s)    << "\n" // 1000ms
              << co::microseconds(1s)    << "\n" // 1000000us
              << co:: nanoseconds(1s)    << "\n" // 1000000000ns
              << co::duration_cast<co::minutes>(1s) << "\n";
              // 0min

    co::duration<int   , std::milli> one_second1 = 2s;
    co::duration<int   , std::nano > one_second2 = 2s;
    co::duration<int               > one_second3 = 2s;    
    co::duration<double, std::milli> one_second4 = 2.5s;

    std::cout << one_second1 << "\n"  // 2000ms
              << one_second2 << "\n"  // 2000000000ns
              << one_second3 << "\n"  // 2s
              << one_second4 << "\n"; // 2500ms

    using fps_24 = co::duration<double, std::ratio<1, 24>>;

    std::cout << fps_24(1s).count() << " frames at 24fps\n";
    // 24 frames at 24fps

    return 0;
}