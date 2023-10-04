#include <iostream>
#include <source_location>

// A function that logs a message and the location from where it was called
void log(const std::string& message,
         const std::source_location& location = std::source_location::current()) {
    std::cout << "Info: " << message << " ("
              << location.file_name() << ":"
              << location.line() << ":"
              << location.column() << ":"
              << location.function_name() << ")\n";
}

int main()
{
    log("Entering main function");

    // Some code here...

    log("Exiting main function");
    
    return 0;
}
