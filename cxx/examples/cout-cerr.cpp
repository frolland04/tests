#include<iostream>

// <iostream>:
// std::ostream cout, cerr;

int main()
{
    std::cout << "Hello\n";
    std::cout << "World!\n";

    // Hello
    // World!

    std::ostream &os{std::cout};
    os << "Yeah,";
    os << "Man.\n";
    
    std::cerr << "ERROR! " << 5 << '\n';
    std::cerr << "ABORTING.\n" ;

    // ERROR! 5
    // ABORTING.

    std::cerr << "ERROR! " << 6 << std::endl;
    std::cerr << "ABORTING.\n" << std::endl;

    // ERROR! 6
    // ABORTING.

    // Hint: Do NOT abuse 'std::endl' (let buffered I/O)

    return 0;
}