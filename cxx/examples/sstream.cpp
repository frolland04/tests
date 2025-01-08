#include<iostream>
#include<sstream>

int main () {

  std::stringstream ss;
  std::string s;
  int i;
  float f;

  ss << "HELLO" << ' ' << 28 << ' ' << 19.9;

  ss.seekg(std::ios::beg);

  ss >> s >> i >> f;

  std::cout << s << ' ' << i << ' ' << f; // "HELLO 28 19.9"

  return 0;
}