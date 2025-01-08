#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

int main()
{
    std::ostream& os{std::cout};

    fs::path p{"/etc"};
    os << p << '\n';

    fs::directory_entry e{p};
    os << e.exists() << ' ' << e.is_directory() << '\n';

    int s{}, n{};
    for (auto const& de : fs::directory_iterator{e}) {
        std::cout << de.path() << '\n';
        if (de.is_regular_file()) s += de.file_size();
        else if (de.is_directory()) ++n;
    }

    os << s << " bytes in files, " << n << " subdirs\n";
    return 0;
}