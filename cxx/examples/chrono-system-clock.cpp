#include <algorithm>
#include <cassert>
#include <complex>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <random>
#include <ranges>
#include <utility>
#include <valarray>
#include <vector>
#include <chrono>
#include <thread>
#include <ctime>


int main()
{
    namespace co = std::chrono;
    using namespace std::chrono_literals;
 
    std::time_t tm = std::time(nullptr); // usually 1s precision 
    auto tp1 = co::system_clock::from_time_t(tm);
 
    std::this_thread::sleep_for(500ms);
 
    auto tp2 = co::system_clock::now();
    auto d = tp2 - tp1;
 
    std::cout << d << ' ' << co::round<co::milliseconds>(d);
    // 1294902190ns 1295ms

    return 0;
}