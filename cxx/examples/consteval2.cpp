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
  if consteval
  {
    return f(i);
  }
  else
  { 
    return i;
  }
}

constinit int x{g(10)}; // g() uses f()

int main() {
    printf("x=%d, g(0)=%d\n", x, g(0));
    // g() not using f(), displays "x=11, g(0)=0"
    return 0;
}

//Note: annotating g() as consteval
//causes g(0)=1