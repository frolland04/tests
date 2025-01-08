#include <iostream>
#include <iterator>
#include <regex>
#include <string>
 
int main()
{
    std::ostream & os{std::cout};

    std::string s = "Some people, when confronted with a problem, think"
                    " \"I know, I'll use regular expressions.\" "
                    "Now they have two problems.";
 
    std::regex re1("REGULAR", std::regex_constants::icase);
    os << std::regex_search(s, re1) << '\n'; // 1

    std::regex re2("three");
    os << std::regex_search(s, re2) << '\n'; // 0

    std::regex wrd(R"(\w+)");
    auto begin = std::sregex_iterator(s.begin(), s.end(), wrd);
    auto end = std::sregex_iterator();
 
    os << std::distance(begin, end) << " words\n";
 
    for (auto it = begin ; it != end ; ++it) {
        std::smatch sm = *it;
        if (sm.str().size() > 6) os << sm.str() << '\n';
    }
}