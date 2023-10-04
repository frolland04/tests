#include <concepts>
#include <type_traits>

struct MyClass {};

struct MyOtherClass { MyOtherClass() {}; };
struct MyOtherClass2 { MyOtherClass2(int) {}; };

template <std::default_initializable T>
class C {};

int main()
{
    static_assert(std::is_default_constructible<MyClass>::value); // OK
    static_assert(std::default_initializable<MyClass>); // OK
    static_assert(std::is_default_constructible<int>::value); // OK

    static_assert(std::is_default_constructible<MyOtherClass>::value); // OK
    // static_assert(std::is_default_constructible<MyOtherClass2>::value); // error.

    C<MyOtherClass> c1;
    // C<MyOtherClass2> c2; // error.

    return 0;
}
