#include "TMP/02/type_descriptor_eng.h"

#include <cassert>
#include <iostream>
#include <sstream>

int main() {
  std::stringstream ss;
  ss << type_descriptor_eng<char>{} << type_descriptor_eng<short>{}
     << type_descriptor_eng<int>{} << type_descriptor_eng<long>{};
  assert(ss.str() == "charshortintlong");

  ss = std::stringstream{};
  ss << type_descriptor_eng<const char>{};
  assert(ss.str() == "const char");

  ss = std::stringstream{};
  ss << type_descriptor_eng<char*>{};
  assert(ss.str() == "pointer to char");

  ss = std::stringstream{};
  ss << type_descriptor_eng<const long*&>{};
  assert(ss.str() == "reference to pointer to const long");

  ss = std::stringstream{};
  ss << type_descriptor_eng<long[23]>{};
  assert(ss.str() == "array of size 23 of long");

  ss = std::stringstream{};
  ss << type_descriptor_eng<int()>{};
  assert(ss.str() == "function returning int");

  ss = std::stringstream{};
  ss << type_descriptor_eng<int (*)()>{};
  assert(ss.str() == "pointer to function returning int");
};
