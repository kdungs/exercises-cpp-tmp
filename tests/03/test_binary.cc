#include "TMP/03/binary.h"

static const unsigned one = binary<1>::value;
// static const unsigned two = binary<2>::value;  // compiler error

static_assert(one == 1, "b(1) == 1");
