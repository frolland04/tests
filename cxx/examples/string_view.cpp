#include <iostream>
#include <string>
#include <string_view>

void f(std::string_view sv) {
    std::cout << sv.substr(0,4) << std::endl; // Hell
}
void g(const std::string & rs) {
    std::cout << rs.substr(0,4) << std::endl; // Hell
}

int main()
{
    std::string s = "Hello from s";
    const char* cs = "Hello from cs";
    std::string_view sv = "Hello from sv";

    // no copy at all, RO-views
    f(s);
    f(cs);
    f(sv);

    g(s);  // no copy at calling site
    g(cs); // copy at call, into temporary string
    // + copy at substr()

    return 0;
}
