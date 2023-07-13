#include <cstdio>
#include <tuple>
#include <type_traits>
#include <optional>
#include <string>
#include <iostream>


std::optional<std::string> get(bool b) {
    if (b) return "OK";
    return std::nullopt;
    // same as
    // return std::optional<std::string>{};
}

int main()
{
    auto result1 = get(true);
    std::cout << result1.has_value() << result1.value() << result1.value_or("NOK") << std::endl;
    
    auto result2 = get(false);
    std::cout << result2.has_value() << result2.value_or("NOK") << std::endl;
    result2.value(); // std::bad_optional_access
    
    return 0;
}