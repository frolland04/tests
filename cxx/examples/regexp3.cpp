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

    std::regex pun(R"([^\w\s]+)");
    std::string n{std::regex_replace(s, pun, "[$&]")};

    os << n << '\n';
    // Some people[,] when confronted with a problem[,] think ["]
    // I know[,] I[']ll use regular expressions[."]
    // Now they have two problems[.]

    std::regex sht(R"(\b\w{1,4}\b)");
    n = std::regex_replace(n, sht, "*");

    os << n << '\n';
    // * people[,] * confronted * * problem[,] think ["]
    // * *[,] *[']* * regular expressions[."]
    // * * * * problems[.]
}