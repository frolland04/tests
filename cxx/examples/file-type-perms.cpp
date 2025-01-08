#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

int main()
{
    std::ostream& os{std::cout};
    std::ofstream f("/tmp/test.txt"); // rw-r-r
    f << "Hello" << std::endl;
 
    auto ss = fs::status("/tmp/test.txt");
    fs::perms p{ss.permissions()};
    fs::file_type t{ss.type()};

    os << ((p & fs::perms::owner_write) != fs::perms::none) << '\n';
    // 1
    os << ((p & fs::perms::others_write) != fs::perms::none) << '\n';
    // 0
    os << (t == fs::file_type::regular) << '\n';
    // 1
    os << (t == fs::file_type::socket) << '\n';
    // 0
    
    return 0;
}