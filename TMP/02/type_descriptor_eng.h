#ifndef TYPE_DESCRIPTOR_ENG_H
#define TYPE_DESCRIPTOR_ENG_H

#include <ostream>

template <typename T>
struct type_descriptor_eng {};

#define MAKE_TYPE_DESCRIPTOR(TYPE)                                        \
  std::ostream& operator<<(std::ostream& os, type_descriptor_eng<TYPE>) { \
    return os << #TYPE;                                                   \
  }

MAKE_TYPE_DESCRIPTOR(char)
MAKE_TYPE_DESCRIPTOR(short)
MAKE_TYPE_DESCRIPTOR(int)
MAKE_TYPE_DESCRIPTOR(long)

#undef MAKE_TYPE_DESCRIPTOR

template <typename T>
std::ostream& operator<<(std::ostream& os, type_descriptor_eng<const T>) {
  return os << "const " << type_descriptor_eng<T>{};
}

template <typename T>
std::ostream& operator<<(std::ostream& os, type_descriptor_eng<T*>) {
  return os << "pointer to " << type_descriptor_eng<T>{};
}

template <typename T>
std::ostream& operator<<(std::ostream& os, type_descriptor_eng<T&>) {
  return os << "reference to " << type_descriptor_eng<T>{};
}

template <typename T>
std::ostream& operator<<(std::ostream& os, type_descriptor_eng<T[]>) {
  return os << "array of " << type_descriptor_eng<T>{};
}

template <typename T, std::size_t N>
std::ostream& operator<<(std::ostream& os, type_descriptor_eng<T[N]>) {
  return os << "array of size " << N << " of " << type_descriptor_eng<T>{};
}

template <typename T>
std::ostream& operator<<(std::ostream& os, type_descriptor_eng<T()>) {
  return os << "function returning " << type_descriptor_eng<T>{};
}

template <typename T>
std::ostream& operator<<(std::ostream& os, type_descriptor_eng<T (*)()>) {
  return os << "pointer to function returning " << type_descriptor_eng<T>{};
}

#endif  // TYPE_DESCRIPTOR_ENG_H
