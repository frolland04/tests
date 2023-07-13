#include <cstdio>
#include <string>

const int x{100};

constexpr int g(int j)
{
    int result{j * x};
    printf("g(%d): %d\n", j, result);
    return result;
}

int i{g(10)};

int main()
{
    printf("main()\n");
    return 0;
}
