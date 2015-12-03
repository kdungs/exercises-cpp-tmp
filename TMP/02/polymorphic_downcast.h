#ifndef POLYMORPHIC_DOWNCAST_H
#define POLYMORPHIC_DOWNCAST_H

#include <type_traits>

template <typename Target, typename Source,
          typename = typename std::enable_if<std::is_base_of<
              Source, typename std::remove_pointer<Target>::type>::value>::type>
Target polymorphic_downcast(Source* x) {
  return static_cast<Target>(x);
}

template <
    typename Target, typename Source,
    typename = typename std::enable_if<std::is_base_of<
        Source, typename std::remove_reference<Target>::type>::value>::type>
Target polymorphic_downcast(Source& x) {
  return static_cast<Target>(x);
}

#endif  // POLYMORPHIC_DOWNCAST_H
