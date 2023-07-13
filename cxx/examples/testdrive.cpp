#include <iostream>
#include <typeinfo>

struct titi;
class tutu;

class tutu
{
    class inner;
};

class tutu::inner {
    int x;
};

struct titi
{
    class ux;    
};

struct toto
{
    int b{};
    void coucou() { std::cout << "coucou!" << std::endl; }
} vt ;

struct toto2 : public toto
{
    int c{};
};

union u;

union u {
    int a;
    int b;
} u1, u2;

enum e {
    X,
    Y
};

enum ee {
    XX, // cannot be name "X"
    Z
};

enum class ece {
    X,
    Y
};

enum class ecee {
    X,
    Z
};

class c
{
    int a{5};

    int get_a() { return a; }

    int get_a_autre(c autre) { return autre.a; }
};

class MyClass {
private:
    int x{20};
    static int y;
    friend void myFunction(MyClass&);
    void myOtherFunction() { return; }
    friend void myFunction2(MyClass&my_obj) {
        my_obj.x = 5;
        my_obj.myOtherFunction();
        my_obj.y = 25;
        std::cout << MyClass::y;
    }
    friend class MyClass2;
};

class MyClass2 {
private:
    void test(MyClass&my_obj) {
        my_obj.x = 5;
        my_obj.myOtherFunction();
        my_obj.y = 25;
        std::cout << MyClass::y;
    }
};

int MyClass::y = 10;

void myFunction(MyClass& my_obj) {
    my_obj.x = 5;
    my_obj.myOtherFunction();
    my_obj.y = 25;
    std::cout << MyClass::y;
}

template<typename T>
void echo(T arg)
{
    std::cout << "1" << typeid(arg).name() << arg << std::endl;
}

template<typename T, typename Q>
void echo(T arg)
{
    std::cout << "2" << typeid(arg).name() << arg << std::endl;
}

template<typename T, typename Q>
void echo(T a, Q b)
{
    std::cout << "2" << typeid(a).name() << a << typeid(b).name() << b << std::endl;
}

template<typename T>
class echoclass
{
    public:
    void test() {
        std::cout << "test" ;
    }
};

int main()
{
    vt.coucou();
    std::cout << vt.b << std::endl;

    u1.a = 5;

    int i = 4;
    echo(i);
    echo(&i);
    echo(4);
    echo<double>(4);
    echo<double>(4.0);
    echo(12.5);
    echo("toto");
    echo("toto", "tutu");

    echoclass<void> e;
    e.test();
}
