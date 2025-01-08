#include<iostream>

int main()
{
    std::ostream &os{std::cout};
    os << 418
       << ' '
       << 419
       << '\n'; // 418 419

    os << std::hex
       << 418
       << ' '
       << 419
       << '\n'; // 1a2 1a3

    os << 44 << " Hello" << '\n';
    // 2c Hello

    os << std::dec
       << 418
       << ' '
       << 419
       << '\n'; // 418 419

    return 0;
}