#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <random>
#include <ranges>
#include <utility>
#include <vector>
#include <functional>
#include <complex>


int main()
{
    using namespace std::complex_literals;
 
    std::complex<double> z1 = 1.5i;
    std::cout << z1; // (0,1.5)

    std::complex<int> z2{2,-1};
    std::cout << z2; // (2,-1)

    // auto z3 = z1 + z2; // error
    auto z3 = z1 + (2.0-1.0i); // OK
    std::cout << z3; // (2,0.5)   

    return 0;
}