#include <cstdio>
#include <string>

//'if consteval is for *functions*
//(obviously annoted 'constexpr')

consteval int f(int i)
{
    return i+1;
}

constexpr int g(int i)
{
  if consteval {
    return f(i);
  }
  else
  { 
    return i;
  }
}

constinit int x{g(10)}; // g() uses f()

struct my_struct {
    int a{0};
};

constinit const auto i{0};
int * p{nullptr};
auto f() {};

static_assert(sizeof(my_struct) > 2); // OK
static_assert(f(0) == 1); // OK
static_assert(std::is_constant_evaluated());  // OK
static_assert(std::is_scalar_v<decltype(i)>); // OK
//static_assert(std::is_scalar_v<my_struct>);   // error
//static_assert(std::is_reference_v<decltype(p)>); // error
static_assert(std::is_pointer_v<decltype(p)>);
static_assert(std::is_function_v<decltype(f)>);

int main() {
    printf("x=%d, g(0)=%d\n", x, g(0));
    // g() not using f(), displays "x=11, g(0)=0"
    return 0;
}

//Note: annotating g() as consteval
//causes g(0)=1