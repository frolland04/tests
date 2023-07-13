#include <cstdio>

void f(int * ptr)
{
    return;
}

void g(int i)
{
    return;
}

void ff(int x, int y) {
    printf("%d\n", x + y);
}
void gg(int x, int y) {
    printf("%d\n", x - y);
}


int main()
{
    int i{5};
    int * pi{&i}; // pi points to i

    printf("%d\n", i);
    printf("%ld\n", (unsigned long)pi);
    printf("%d\n", *pi);

    int ai[2]{ 10, 20};
    printf("%d\n", *ai);
    printf("%d\n", *(ai+1));

    int x{50};
          int *       p1{&x};  // non-const pointer to non-const int
    const int *       p2{&x};  // non-const pointer to const int
          int * const p3{&x};  // const pointer to non-const int
    const int * const p4{&x};  // const pointer to const int 

    *p1 = 100;
    p1 = &i;

    //*p2 = 200; // error, read-only location
    p2 = &i;

    //*p3 = 300;
    //p3 = &i; // error, read-only variable

    //*p4 = 400; // error
    //p4 = &i;   // error

    pi = nullptr;
    f(pi);
    //g(pi); // error, invalid conversion
    
    void (*adds)(int,int) = ff;
    adds(10, 1); //
    void (*minus)(int,int) = gg;
    minus(10, 1); //

    return 2;
}
