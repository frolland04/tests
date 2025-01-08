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

int main()
{
    std::chrono::high_resolution_clock clk;
    auto tp1 = clk.now(); // timepoint
    std::cout << tp1 << '\n'; // 2023-11-30 09:43:35.855977251

    std::chrono::milliseconds ms(1500); // duration
    std::this_thread::sleep_for(ms);
    auto tp2 = clk.now();
    std::cout << tp2 << '\n'; // 2023-11-30 09:43:37.356087687

    auto d1 = tp2 - tp1; // duration
    std::cout << d1 << '\n';
    std::cout << std::chrono::duration_cast<std::chrono::seconds>(d1) << '\n';

    std::chrono::duration<double> d2 = tp2 - tp1;
    std::cout << d2 << '\n';
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(d2) << '\n';

    // 1500143602ns
    // 1s
    // 1.50014s
    // 1500ms
    
    return 0;
}