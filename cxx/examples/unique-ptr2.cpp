#include <iostream>
#include <memory>

struct C {
  void f() {};
};

std::unique_ptr<C> ff() {
  std::unique_ptr<C> t = std::make_unique<C>();
  return t;
}

int main()
{
  auto p = ff();
  // auto p2 = p; // error.

  p->f();

  // 'delete' not needed
  // + exception safe

  return 0;
}
