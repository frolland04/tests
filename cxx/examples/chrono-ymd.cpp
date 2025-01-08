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
 
    auto ymd1 = co::year_month_day(
        2020y, co::January, 31d
    );
    std::cout << ymd1 << '\n'; // 2020-01-31
 
    auto ymd2 = co::year_month_day(
        co::April / co::Monday[co::last] / 2023y
    );
    std::cout << ymd2 << '\n'; // 2023-04-24
 
    auto now = co::system_clock::now();
    auto ymd3 = co::year_month_day(
        co::floor<co::days>(now)
    );
    std::cout << ymd3 << '\n'; // 2023-12-15

    return 0;
}