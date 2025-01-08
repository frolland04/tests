#include<iostream>
#include<fstream>

int main () {

  std::fstream fs;
  std::string s;

  fs.open("test.txt", std::fstream::in | std::fstream::out | std::fstream::app);
  if (fs.is_open())
  {
    fs << "HELLO";

    fs.seekg(std::ios::beg);
    
    fs >> s;

    std::cout << s; // "HELLO"
  }

  return 0;
}