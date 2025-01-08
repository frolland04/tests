#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

int main()
{
    std::ostream& os{std::cout};

    std::string s{"/tmp"};
    fs::path p{s};
    os << p << '\n';
    os << p.is_absolute() << '\n';
    // "/tmp"
    // 1

    fs::current_path(p);
    os << fs::current_path() << '\n'; // cd
    // "/tmp"

    os << fs::exists(p) << '\n';
    // 1
    os << fs::exists("/he/has/left") << '\n';
    // 0

    os << p.filename() << '\n';
    // "tmp"
    os << fs::path("/he/has/left").filename() << '\n';
    // "left"
    os << fs::path("/tmp/log.txt").filename() << '\n';
    // "log.txt"
    os << fs::path("/").filename() << '\n';
    // ""
    os << fs::path("/tmp/log.txt").extension() << '\n';
    // ".txt"

    return 0;
}