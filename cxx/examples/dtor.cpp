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
    MyFile() {
        std::cout << "Opening file" << std::endl;
        f.open("myfile.tmp", std::ios::in);
    }

    ~MyFile() {
        std::cout << "Closing file" << std::endl;
        f.close();
    }

    void write(const std::string & s) {
        /*if (f.is_open())*/ {
            std::cout << "Writing " << s << std::endl;
            f << s;
        }
    }

private:
    std::fstream f;               
};

int main()
{
    MyFile mf;
    mf.write("hello");
    mf.write("world");
}
