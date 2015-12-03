#include "TMP/02/type_descriptor.h"

#include <cassert>
#include <iostream>
#include <sstream>

int main() {
  std::stringstream ss;
  ss << type_descriptor<char>{} << type_descriptor<short>{}
     << type_descriptor<int>{} << type_descriptor<long>{};
  assert(ss.str() == "charshortintlong");

  ss = std::stringstream{};
  ss << type_descriptor<const char>{};
  assert(ss.str() == "const char");

  ss = std::stringstream{};
  ss << type_descriptor<char*>{};
  assert(ss.str() == "char*");
  
  ss = std::stringstream{};
  ss << type_descriptor<const long*&>{};
  assert(ss.str() == "const long*&");
  
  ss = std::stringstream{};
  ss << type_descriptor<long[23]>{};
  assert(ss.str() == "long[23]");
  
  ss = std::stringstream{};
  ss << type_descriptor<int()>{};
  assert(ss.str() == "int()");
  
  ss = std::stringstream{};
  ss << type_descriptor<int(*)()>{};
  assert(ss.str() == "int(*)()");
}
