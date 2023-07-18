namespace ns {

int variable{0};
void function(int i);

function(variable);

}

function(variable);         // (1): error

ns::function(ns::variable); // (2): OK


namespace ns {

function(variable);         // (3): OK

}

namespace ns1 {
namespace ns2 {

~~~

}
}

// Or

namespace ns1::ns2 { 

~~~

}


namespace ns1 {

int variable{0};

namespace ns2 {

int i{ns1::variable};

}
}

int variable{0};

namespace ns1 {

int variable{1}     // OK. We have `variable` and `ns::variable`.

static_assert(::variable == 0);  // OK. `::variable` is `variable`, not `ns::variable`.

}

int v0{0};

namespace ns1 {

int v1{1};

namespace ns2 {

int v2{2};

int all_v{v2 + v1 + v0}; // OK.

}

namespace ns1::ns2::ns3 { int v{0}; }

namespace ns = ns1::ns2::ns3;

static_assert(ns::v == ns1::ns2::n3::v) // OK. Same variable.


void function(int i); 

namespace ns {

using function();

}

ns::function(0);


namespace ns1 {

int v{0};
void f(int i);

}

namespace ns2 {

using namespace ns1;

}

ns2::f(ns2::v);

namespace {

void f();

}

void g();
