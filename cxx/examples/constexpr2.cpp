#include <cstdio>

const int x{100};
constexpr int g(int j) {
    if constexpr(x == 100)
    {
        printf("Implements x 100\n");
        return {j * x};
    }
    else
    {
        printf("Implements x 10\n");
        return {j * 10};
    }
}

int main()
{
    printf("%d\n", g(5));
    return 0;
}