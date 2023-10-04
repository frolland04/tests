#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include <tuple>
#include <type_traits>

class MyFile {
public:
    MyFile(const std::string & _name) : name{_name} {
        std::cout << "Opening file '" << name << "'" << std::endl;
        f.open(name, std::ios::in);
    }

    ~MyFile() {
        std::cout << "Closing file '" << name << "'" << std::endl;
        f.close();
    }

    void write(const std::string & s) {
        if (f.is_open()) {
            std::cout << "Writing '" << s << "' into file '" << name << "'" << std::endl;
            f << s;
        }
    }

private:
    std::string name;
    std::fstream f;               
};

int main()
{
    MyFile mf{"1.tmp"};
    mf.write("hello");
    mf.write("world");

    if (true)
    {
        MyFile mf2{"2.tmp"};
        mf2.write("auto");
    }

    return 0;
}
