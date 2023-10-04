#include <type_traits>
#include <cstdio>
#include <tuple>

int main()
{
    int a[2] = {1, 2};
    auto [x, y] = a;
    static_assert(std::is_same_v<decltype(x), int>);

    auto & [xa, ya] = a;
    static_assert(std::is_same_v<decltype(xa), int>);

    struct S
    {
        int x1{0};
        double y1{0};
    };
    
    const auto [xx, yy] = S{1, 2.5};
    static_assert(std::is_same_v<decltype(xx), const int>);
    static_assert(std::is_same_v<decltype(yy), const double>);
    printf("%d, %.2f\n", xx, yy);

    std::tuple<float, char, int> tpl(6.2f, 'n', 32);
    auto & [aa, bb, cc] = tpl;
    static_assert(std::is_same_v<decltype(aa), float>);
    static_assert(std::is_same_v<decltype(bb), char>);
    static_assert(std::is_same_v<decltype(cc), int>);
    printf("%.2f, %c, %d\n", aa, bb, cc);

    return 0;
}