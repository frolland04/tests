#include <cmath>
#include <cstdio>
#include <fstream>
#include <functional>
#include <iostream>
#include <optional>
#include <string>
#include <tuple>
#include <type_traits>

// A *default* constructor is a constructor that either has *no* parameters,
// or if it has parameters, all the parameters have *default* values.

// If *no user-defined* constructor exists for a class A and one is needed,
// the compiler implicitly declares a *default* parameterless constructor A::A()
// .

//  The *default* constructor is auto-generated if there is *no user-declared*
//  constructor.

//  The destructor is auto-generated if there is *no user-declared* destructor.

class A {
   public:
    // this disable A() default ctor generation
     A(int i) { std::cout << "A" << std::endl; }

    ~A() { std::cout << "~A" << std::endl; }

    void f() { std::cout << "f()" << std::endl; }
};

class B : public A {
   public:
    B(int i, int j) : A{0} { std::cout << "B" << std::endl; }
    // have a look at initializer list
    ~B() { std::cout << "~B" << std::endl; }

    void g() { return f(); }
};

int main()
{
    // A aa; // default ctor is disabled by A(int)
    A a{1};
    B b{10, 20};

    // B bb{10}; // error
    // A(int) not available on B
    // even if B inherits A.

    b.g();
    b.f();

    return 0;
}
