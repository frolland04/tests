#include <cmath>
#include <cstdio>
#include <fstream>
#include <functional>
#include <iostream>
#include <optional>
#include <string>
#include <tuple>
#include <type_traits>

class C {
    using S = std::string;

   public:
    C(const S& _name = "?") : m_name{_name} {
        std::cout << "ctor " << m_name << std::endl;
    }
    ~C() { std::cout << "dtor " << m_name << std::endl; }
    C& operator=(const C& _other) {
        std::cout << m_name << "=" << _other.m_name << std::endl;
        return *this;
    }
    C(const C& _other) {
        std::cout << "copying " << _other.m_name << std::endl;
        m_name = "copy-of-" + _other.m_name;
    }
    const S& name() const { return m_name; }
    void set_name(const S& _name) { m_name = _name; }

    // C(C && _other) = delete;
    //  ^^^ not easy to test,
    //  compiler is free to eliminate redundant calls to ctor
    // C& operator=(C && _other) = delete;
    //  ^^^ default implementation is calling 'operator=(C&)'

    C(C&& _other) : m_name{std::move(_other.m_name)} {
        std::cout << "(&&) " << m_name << std::endl;
        m_name.insert(0, "copy-of-");
    }

    C& operator=(C&& _other) {
        m_name = std::move(_other.m_name);
        std::cout << "=(&&) " << m_name << std::endl;
        m_name.insert(0, "assign-from-");
        return *this;
    }

   private:
    S m_name{"!"};
};

C process_v(const C _arg)  // "pass-by-value"
{
    return C{_arg.name() + "p"};
    // "return-by-value", RVO
}

C process_v2(const C _arg)  // "pass-by-value"
{
    C t{_arg.name() + "p"};
    return t;
    // "return-by-value", NRVO
}

C process(const C& _arg)  // "pass-by-reference"
{
    return C{_arg.name() + "p"};
    // "return-by-value", RVO
}

C process2(const C& _arg)  // "pass-by-reference"
{
    C t{_arg.name() + "p"};
    return t;
    // "return-by-value", NRVO
}

int main()
{
    std::cout << "-1-" << std::endl;
    C c1{"c1"}, c2{"c2"}, c3{"c3"}, c4{"c4"};

    // ...

    std::cout << "-4-" << std::endl;
    c4 = process2(c3); // implicit assign move 
    c4.set_name("c4");
    
    std::cout << "-6-" << std::endl;
    C c6 = std::move(c1);

    std::cout << "-7-" << std::endl;
    C c7{std::move(c2)};

    std::cout << "-8-" << std::endl;

    return 0;
}
