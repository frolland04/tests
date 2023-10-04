#include <iostream>
#include <system_error>  // for std::error_code and std::error_condition

enum class Error {
  Success  = 200,
  NotFound = 400,
  Timeout  = 500,
};

class Category : public std::error_category {
public:
  virtual const char* name() const noexcept { return "custom"; }
  virtual std::string message(int ev) const {
    switch (ev) {
      case 200: return "OK";
      case 400: return "400 Not Found";
      case 500: return "500 Timeout";
      default: return "Unknown error";
    }
  }
} custom_category;


namespace std {
template <>
struct is_error_code_enum<Error> : true_type {};
} 
std::error_code make_error_code(Error e) {
  return {static_cast<int>(e), custom_category};
}

int main()
{
  std::error_code ec = Error::Timeout;
  if (ec) {
      std::cerr << "Error occurred: " << ec.message() << " (" << ec.value() << ")\n";
  }
  else {
      std::cout << "Successful.\n";
  }

  return 0;
}
