#include<iostream>
#include<iomanip>

int main()
{
    std::ostream &os{std::cout};
    os << std::fixed << std::setprecision(3);

    os << 48.79422 << '\n'
       << 2.048 << '\n'
       << 2048.0 << '\n'
       
    // 48.794
    // 2.048
    // 2048.000

       << std::setw(10)
       << 48.79422 << '\n'
       << std::setw(10)
       << 2.048 << '\n'
       << std::setw(10)
       << 2048.0 << '\n';

    //   48.794
    //    2.048
    // 2048.000

    return 0;
}