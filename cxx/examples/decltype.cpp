#include <cstdio>
#include <type_traits>

auto f(int i) -> decltype(auto)
{
    if (i < 0)
        return 0;
    else
        return 1;
}

int main()
{
    printf("Hello!\n");

    int i{0};

    auto & y{i};
    auto z{i};
    auto zz{y};
    decltype(auto) zzz{y};

    int * pi{&i};
    auto ii{pi};
    decltype(auto) iii{pi};

    static_assert(std::is_same_v<decltype(i), int>); // OK.
    // FAILED! static_assert(std::is_same_v<decltype(i), float>);
    static_assert(std::is_scalar_v<decltype(i)>);
    // FAILED! static_assert(std::is_reference_v<decltype(i)>);
    // FAILED! static_assert(std::is_pointer_v<decltype(i)>);

    static_assert(std::is_same_v<decltype(y), int&>); // OK.
    // FAILED! static_assert(std::is_same_v<decltype(y), int>);
    // FAILED! static_assert(std::is_scalar_v<decltype(y)>);
    static_assert(std::is_reference_v<decltype(y)>);
    // FAILED! static_assert(std::is_pointer_v<decltype(y)>);
 
    static_assert(std::is_same_v<decltype(z), int>); // OK.
    // FAILED! static_assert(std::is_same_v<decltype(z), int&>);
    static_assert(std::is_scalar_v<decltype(z)>);
    // FAILED! static_assert(std::is_reference_v<decltype(z)>);
    // FAILED! static_assert(std::is_pointer_v<decltype(z)>);

    static_assert(std::is_same_v<decltype(zz), int>); // OK.
    // FAILED! static_assert(std::is_same_v<decltype(zz), int&>);
    static_assert(std::is_scalar_v<decltype(zz)>);
    // FAILED! static_assert(std::is_reference_v<decltype(zz)>);
    // FAILED! static_assert(std::is_pointer_v<decltype(zz)>);

    static_assert(std::is_same_v<decltype(zzz), int&>);
    // FAILED! static_assert(std::is_same_v<decltype(zzz), int>);
    // FAILED! static_assert(std::is_scalar_v<decltype(zzz)>);
    static_assert(std::is_reference_v<decltype(zzz)>);
    // FAILED! static_assert(std::is_pointer_v<decltype(zzz)>);

    static_assert(std::is_same_v<decltype(pi), int*>); // OK.
    // FAILED! static_assert(std::is_same_v<decltype(pi), int>);
    // FAILED! static_assert(std::is_same_v<decltype(pi), int&>);
    static_assert(std::is_scalar_v<decltype(pi)>);
    // FAILED! static_assert(std::is_reference_v<decltype(pi)>);
    static_assert(std::is_pointer_v<decltype(pi)>);

    static_assert(std::is_same_v<decltype(ii), int*>); // OK.
    // FAILED! static_assert(std::is_same_v<decltype(ii), int>);
    // FAILED! static_assert(std::is_same_v<decltype(ii), int&>);
    static_assert(std::is_scalar_v<decltype(ii)>);
    // FAILED! static_assert(std::is_reference_v<decltype(ii)>);
    static_assert(std::is_pointer_v<decltype(ii)>);

    static_assert(std::is_same_v<decltype(iii), int*>); // OK.
    static_assert(std::is_scalar_v<decltype(iii)>);
    // FAILED! static_assert(std::is_reference_v<decltype(iii)>);
    static_assert(std::is_pointer_v<decltype(iii)>);

    static_assert(std::is_function_v<decltype(f)>);

    return 0;
}