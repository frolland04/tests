#include <new>  // For std::launder
#include <iostream>

struct C {
    const int i;
    C(int v) : i{v} {
        std::cout << "C ctor, i: " << i << '\n';
    }
};

int main()
{
    // Allocate space suitable to hold an object of type C
    alignas(C) unsigned char s[sizeof(C)];

    // Construct an object using 'placement new'
    C* obj = new(s) C(42);
    std::cout << "First object, i: " << obj->i << '\n';

    // Destroy the first object
    obj->~C();

    // Construct a second object at the same location
    obj = new(s) C(84);
    
    // Correctly access the second object using std::launder
    C* obj2 = std::launder(obj);
    std::cout << "Second object, i: " << obj2->i << '\n';

    // Call the destructor
    obj2->~C();

    // C ctor, i: 42
    // First object, i: 42
    // C ctor, i: 84
    // Second object, i: 84

    return 0;
}
