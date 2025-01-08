#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

int main()
{
    fs::path d{"/tmp/example"}, f1(d/"test1.txt"), f2(d/"test2.txt"); // :-D

    fs::create_directory(d);

    std::ofstream s{f1};
    s << "Hello!" << std::endl;

    fs::copy(f1, "/tmp", fs::copy_options::overwrite_existing);    
    fs::rename(f1, f2);

    std::cout << fs::file_size(f2) << '\n'; // 7
    fs::resize_file(f2, 50);
    std::cout << fs::file_size(f2) << '\n'; // 50
    
    fs::remove(f2);
    fs::remove(d);
    
    return 0;
}
