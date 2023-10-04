#include <cstdio>
#include <string>

const int x{100};
constexpr int g(int j) { return {j * x}; }

consteval int gg(int j) { return {j * x}; }

static int cc{gg(11)};

int main()
{
    const int i{5};
    // i = 5; // error, RO variable

    const int& alias_i{i};
    // alias_i = 6; // error, RO reference

    const int* const pi{&i};
    //  pi = &i; // error, RO variable
    // *pi = 6;  // error, RO location

    static const int j{6};  // longlasting scope

    std::string t[i];
    printf("%d, %d\n", sizeof(std::string), sizeof(t));

    static constinit const int c{g(12)};
    // constinit int d{0}; // error, only applied to static
    cc = 0;
    // c = 0; //error

    int z{gg(100)};
    printf("%d, %d\n", cc, z);

    return 0;
}