#include <string>
#include <list>
#include <initializer_list>
		

struct C {
    C() : i{0} {};
    int i;
};

struct D : public C {
    D(std::initializer_list<int> &i) : C{}, li{i} {};
    std::list<int> li;
};


int main()
{
    int i{10};
    int & ri{i};
    int * pi{&i};
    std::string s{"Hello World!"};
    std::string s2{s};
    
    int a[10]{0,1,2,3,4,5,6,7,8,9};

    std::list<int> v{1,2,3,4};
    // this is NOT a variable-length argument list ctor call.
    // std::list(std::initializer&), array of objects of same type.

    return 0;
}