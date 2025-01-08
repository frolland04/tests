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

    auto dt{co::system_clock::now()};
    // co::time_point<co::system_clock>

    auto tp{co::floor<co::days>(dt)};
    auto hms{co::floor<co::milliseconds>(dt-tp)}; 

    std::cout << dt << " " << co::year_month_day(tp) << " "
                           << co::hh_mm_ss(hms) << "\n";

    // 2023-12-15 15:20:55.092978595 2023-12-15 15:20:55.092

    dt += co::days(1) + co::minutes(5);
    tp = co::floor<co::days>(dt);
    hms = co::floor<co::milliseconds>(dt-tp); 

    std::cout << dt << " " << co::year_month_day(tp) << " "
                           << co::hh_mm_ss(hms) << "\n";

    // 2023-12-16 15:25:55.092978595 2023-12-16 15:25:55.092

    return 0;
}