#include <iostream>
#include <regex>
#include <string>

int main()
{
    std::ostream & os{std::cout};

    std::string s1{"example@domain.com"}, s2{"one@big"};
    std::regex is_email(R"((\w+)(\.\w+)*@(\w+)(\.\w+)+)");

    os << std::regex_match(s1, is_email) << '\n'; // 1
    os << std::regex_match(s2, is_email) << '\n'; // 0

    std::string s3{"one"}, s4{"ONE"}, s5{"2"}, s6{"five"};
    std::string pat{"1|one|2|two"};
    std::regex is_nbs(pat), is_nbi{pat, std::regex_constants::icase};

    os << std::regex_match(s3, is_nbs) << '\n'; // 1
    os << std::regex_match(s4, is_nbs) << '\n'; // 0
    os << std::regex_match(s4, is_nbi) << '\n'; // 1
    os << std::regex_match(s5, is_nbs) << '\n'; // 1
    os << std::regex_match(s6, is_nbs) << '\n'; // 0
    
    return 0;
}
