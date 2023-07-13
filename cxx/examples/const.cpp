#include <cstdio>



int main()
{
    const int i{5};
    //i = 5; // error, immutable

    const int & alias_i{i};
    //alias_i = 6; // error, RO reference

    const int * const pi{&i};
    
    return 0;
}