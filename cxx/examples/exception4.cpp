#include <iostream>
#include <exception>

// Define a custom exception type that derives from std::exception
class MyException : public std::exception {
public:
    // Override the what() member function
    const char* what() const noexcept override {
        return "MyException occurred!";
    }
};

int main()
{
    try {
        // Throw the custom exception
        throw MyException();
    } 
    catch (const std::exception& e) {
        // Catch it by reference to base type and print the error message
        std::cerr << "Exception caught: " << e.what() << '\n';
    }
    
    return 0;
}
