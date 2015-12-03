#ifndef BINARY_H
#define BINARY_H

template <unsigned long N>
struct binary {
  static_assert(N <= 1, "digits in binary number have to be 1 or 0");
  static const unsigned value = binary<N / 10>::value * 2 + N % 10;
};

template <>
struct binary<0> {
  static const unsigned value = 0;
};

#endif  // BINARY
