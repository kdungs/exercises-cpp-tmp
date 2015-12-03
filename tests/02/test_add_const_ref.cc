#include "TMP/02/add_const_ref.h"

#include <type_traits>

static_assert(std::is_same<add_const_ref<int>::type, const int&>::value,
              "int -> const int&");
static_assert(std::is_same<add_const_ref<int&>::type, int&>::value,
              "int -> const int&");
