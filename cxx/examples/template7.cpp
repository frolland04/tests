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

using S = std::string;

template<class T>
using V = std::vector<T>;

template<class T>
using pointer = T*;

template<class T>
using pair = std::pair<T, T>;

int main()
{
    V<int> v;

    pointer<int> pi;

    pair<int> ii;

    return 0;
} 
