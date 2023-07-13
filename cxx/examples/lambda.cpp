#include <cstdio>
#include <iostream>
#include <optional>
#include <string>
#include <tuple>
#include <type_traits>

int aa{0}, bb{0};
auto ll = [](int i) {
    aa += i;
    // b++;
    return aa>=10;
};
bool res{ll(2)};

int main() {

    int a{0}, b{0};
    auto l2{[&a, b](int i) {
        a += i;
        // b++;
        return a>=10;
    }};

    auto l3 = [&a](int i) -> bool {
        a += i;
        return a>=10;
    };

    bool b5{l2(2)};
    printf("%d, %d\n", b5, a); // 0, 2
    bool b8{l2(8)};
    printf("%d, %d\n", b8, a); // 1, 10

    auto l5 = [](int i) -> bool { return true; };
    bool (*pfl5)(int){l5};

    return 0;
}