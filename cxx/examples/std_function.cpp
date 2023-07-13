#include <cstdio>
#include <iostream>
#include <optional>
#include <string>
#include <tuple>
#include <type_traits>
#include <functional>

void print(int i) {
    std::cout << i << '\n';
} 
struct S {
    int num{10};

    void operator()(int i) {
        std::cout << i << '\n';
    }
    void add(int i) {
        std::cout << num + i << '\n';
    }
};

int main()
{   
    // store a free function 
    std::function<void(int)> disp = print;
    disp(-9); // -9
 
    // store a lambda
    std::function<void()> disp_42 = []() { print(42); };
    disp_42(); // 42
 
    // store the result of a call to std::bind
    std::function<void()> disp_99 = std::bind(print, 99);
    disp_99(); // 99
 
    // store a call to a member function
    std::function<void( S&, int)> add = &S::add;
    S foo;
    add(foo, 1); // 11
 
    // store a call to a data member accessor
    std::function<int(S &)> num = &S::num;
    std::cout << "num: " << num(foo) << '\n'; // 10
 
    // store a call to a function object
    std::function<void(int)> functor = S();
    functor(18); // 18

    // **********************************************************************

    // invoke a free function
    std::invoke(print, -9);
 
    // invoke a lambda
    std::invoke([]() { print(42); });
 
    // invoke a member function
    // S foo;
    std::invoke(&S::add, foo, 1);
 
    // invoke (access) a data member
    std::cout << "num_: " << std::invoke(&S::num, foo) << '\n';
 
    // invoke a function object
    std::invoke(S(), 18);


    return 0;
}