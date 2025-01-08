#include<iostream>

int main()
{
    std::ostream &os{std::cout};
    std::istream &is{std::cin};

    int n1, n2, n3, n4;
    is >> n1 >> n2 >> n3 >> n4;

    os << n1 << ' ' << n2 << ' '
       << n3 << ' ' << n4 << '\n' ;
    // enter: 125 26 2 5
    // displays: 125 26 2 5

    // enter: 125 20.9 2 5
    // displays: 125 20 0 0

    float f1, f2, f3, f4;
    is >> f1 >> f2 >> f3 >> f4;
    os << f1 << ' ' << f2 << ' '
       << f3 << ' ' << f4 << '\n' ;

    // enter: 125 20.9 2 5
    // display: 125 20.9 2 5

    return 0;
}