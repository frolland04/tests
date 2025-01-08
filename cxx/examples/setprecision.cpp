#include<iostream>
#include<iomanip>

int main()
{
    std::ostream &os{std::cout};
    auto f1{4.2895418598}, f2{484.2895418598};

    os << f1 << ' '
       << f2 << '\n';
    // 4.28954 484.29

    os << std::setprecision(3)
       << f1 << ' '
       << f2 << '\n';    
    // 4.29 484
    
    os << std::setprecision(2)
       << f1 << ' '
       << f2 << '\n';    
    // 4.3 4.8e+02

    os << std::fixed
       << f1 << ' '
       << f2 << '\n';
    // 4.29 484.29

    return 0;
}