#ifndef TYPE_DESCRIPTOR_H
#define TYPE_DESCRIPTOR_H

#include <ostream>

template <typename T>
struct type_descriptor {};

#define MAKE_TYPE_DESCRIPTOR(TYPE)                                    \
  std::ostream& operator<<(std::ostream& os, type_descriptor<TYPE>) { \
    return os << #TYPE;                                               \
  }

MAKE_TYPE_DESCRIPTOR(char)
MAKE_TYPE_DESCRIPTOR(short)
MAKE_TYPE_DESCRIPTOR(int)
MAKE_TYPE_DESCRIPTOR(long)

#undef MAKE_TYPE_DESCRIPTOR

template <typename T>
std::ostream& operator<<(std::ostream& os, type_descriptor<const T>) {
    return os << "const " << type_descriptor<T>{};
}

template <typename T>
std::ostream& operator<<(std::ostream& os, type_descriptor<T*>) {
    return os << type_descriptor<T>{} << '*';
}

template <typename T>
std::ostream& operator<<(std::ostream& os, type_descriptor<T&>) {
    return os << type_descriptor<T>{} << '&';
}

template <typename T, std::size_t N>
std::ostream& operator<<(std::ostream& os, type_descriptor<T[N]>) {
  return os << type_descriptor<T>{} << '[' << N << ']';
}

template <typename T>
std::ostream& operator<<(std::ostream& os, type_descriptor<T()>) {
  return os << type_descriptor<T>{} << "()";
}

template <typename T>
std::ostream& operator<<(std::ostream& os, type_descriptor<T(*)()>) {
  return os << type_descriptor<T>{} << "(*)()";
}

#endif  // TYPE_DESCRIPTOR_H
