#ifndef ADD_CONST_REF_H
#define ADD_CONST_REF_H

#include <type_traits>

template <typename T, bool convert>
struct add_const_ref_impl;

template <typename T>
struct add_const_ref_impl<T, true> {
  using type = const T&;
};

template <typename T>
struct add_const_ref_impl<T, false> {
  using type = T;
};

template <typename T>
struct add_const_ref : add_const_ref_impl<T, !std::is_reference<T>::value> {};

#endif  // ADD_CONST_REF_H
